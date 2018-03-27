#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <net/if.h>
#include <stdio.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/filter.h>
#include <stdlib.h>

#define ETH_HDR_LEN 14
#define IP_HDR_LEN 20
#define UDP_HDR_LEN 8
#define TCP_HDR_LEN 20

static int sock;

void sig_handler(int sig) 
{
    struct ifreq ethreq;
    if(sig == SIGTERM)
        printf("SIGTERM recieved, exiting.../n");
    else if(sig == SIGINT)
        printf("SIGINT recieved, exiting.../n");
    else if(sig == SIGQUIT)
        printf("SIGQUIT recieved, exiting.../n");
    // turn off the PROMISCOUS mode 
    strncpy(ethreq.ifr_name, "eth1", IFNAMSIZ);
    if(ioctl(sock, SIOCGIFFLAGS, &ethreq) != -1) {
        ethreq.ifr_flags &= ~IFF_PROMISC;
        ioctl(sock, SIOCSIFFLAGS, &ethreq);
    }
    close(sock);
    exit(0);
}

int main(int argc, char ** argv) {
    int n;
    char buf[2048];
    unsigned char *ethhead;
    unsigned char *iphead;
    struct ifreq ethreq;
    struct sigaction sighandle;

#if 0
    $tcpdump ip -s 2048 -d host 192.168.1.2
        (000) ldh      [12]
        (001) jeq      #0x800           jt 2 jf 7
        (002) ld       [26]
        (003) jeq      #0xc0a80102      jt 6 jf 4
        (004) ld       [30]
        (005) jeq      #0xc0a80102      jt 6 jf 7
        (006) ret      #2048
        (007) ret      #0
#endif

#if 0
        测试访问www.qq.com 
        ping www.qq.com 得到ip地址为:101.226.103.106
        tcpdump -dd host 101.226.103.106
         { 0x28, 0, 0, 0x0000000c },
         { 0x15, 0, 4, 0x00000800 },
         { 0x20, 0, 0, 0x0000001a },
         { 0x15, 8, 0, 0x65e2676a },
         { 0x20, 0, 0, 0x0000001e },
         { 0x15, 6, 7, 0x65e2676a },
         { 0x15, 1, 0, 0x00000806 },
         { 0x15, 0, 5, 0x00008035 },
         { 0x20, 0, 0, 0x0000001c },
         { 0x15, 2, 0, 0x65e2676a },
         { 0x20, 0, 0, 0x00000026 },
         { 0x15, 0, 1, 0x65e2676a },
         { 0x6, 0, 0, 0x0000ffff },
         { 0x6, 0, 0, 0x00000000 },
#endif
        struct sock_filter bpf_code[] = {
            { 0x28, 0, 0, 0x0000000c },
            { 0x15, 0, 5, 0x00000800 },
            { 0x20, 0, 0, 0x0000001a },
            { 0x15, 2, 0, 0x65e2676a },
            { 0x20, 0, 0, 0x00000026 },
            { 0x15, 0, 1, 0x65e2676a },
            { 0x6, 0, 0, 0x0000ffff },
            { 0x6, 0, 0, 0x00000000 }
        };

    struct sock_fprog filter;
    filter.len = sizeof(bpf_code)/sizeof(bpf_code[0]);
    filter.filter = bpf_code;

    sighandle.sa_flags = 0;
    sighandle.sa_handler = sig_handler;
    sigemptyset(&sighandle.sa_mask);
    //sigaddset(&sighandle.sa_mask, SIGTERM);
    //sigaddset(&sighandle.sa_mask, SIGINT);
    //sigaddset(&sighandle.sa_mask, SIGQUIT);
    sigaction(SIGTERM, &sighandle, NULL);
    sigaction(SIGINT, &sighandle, NULL);
    sigaction(SIGQUIT, &sighandle, NULL);

    // AF_PACKET allows application to read pecket from and write packet to network device
    // SOCK_DGRAM the packet exclude ethernet header
    // SOCK_RAW raw data from the device including ethernet header
    // ETH_P_IP all IP packets 
    if((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP))) == -1) {
        perror("socket");
        exit(1);
    }

    // set NIC to promiscous mode, so we can recieve all packets of the network
    strncpy(ethreq.ifr_name, "enp0s25", IFNAMSIZ);
    if(ioctl(sock, SIOCGIFFLAGS, &ethreq) == -1) {
        perror("ioctl");
        close(sock);
        exit(1);
    }

    ethreq.ifr_flags |= IFF_PROMISC;
    if(ioctl(sock, SIOCSIFFLAGS, &ethreq) == -1) {
        perror("ioctl");
        close(sock);
        exit(1);
    }

#if 0 
    // attach the bpf filter
    if(setsockopt(sock, SOL_SOCKET, SO_ATTACH_FILTER, &filter, sizeof(filter)) == -1) {
        perror("setsockopt");
        close(sock);
        exit(1);
    }
#endif

    while(1) {
        n = recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL);
        if(n < (ETH_HDR_LEN+IP_HDR_LEN+UDP_HDR_LEN)) {
            printf("invalid packet\n");
            continue;
        }

        printf("%d bytes recieved\n", n);

        ethhead = buf;
        printf("Ethernet: MAC[%02X:%02X:%02X:%02X:%02X:%02X]", ethhead[0], ethhead[1], ethhead[2],
                ethhead[3], ethhead[4], ethhead[5]);
        printf("->[%02X:%02X:%02X:%02X:%02X:%02X]", ethhead[6], ethhead[7], ethhead[8],
                ethhead[9], ethhead[10], ethhead[11]);
        printf(" type[%04x]\n", (ntohs(ethhead[12]|ethhead[13]<<8)));

        iphead = ethhead + ETH_HDR_LEN;
        // header length as 32-bit
        printf("IP: Version: %d HeaderLen: %d[%d]", (*iphead>>4), (*iphead & 0x0f), (*iphead & 0x0f)*4);
        printf(" TotalLen %d", (iphead[2]<<8|iphead[3]));
        printf(" IP [%d.%d.%d.%d]", iphead[12], iphead[13], iphead[14], iphead[15]);
        printf("->[%d.%d.%d.%d]", iphead[16], iphead[17], iphead[18], iphead[19]);
        printf(" %d", iphead[9]);

        if(iphead[9] == IPPROTO_TCP)
            printf("[TCP]");
        else if(iphead[9] == IPPROTO_UDP)
            printf("[UDP]");
        else if(iphead[9] == IPPROTO_ICMP)
            printf("[ICMP]");
        else if(iphead[9] == IPPROTO_IGMP)
            printf("[IGMP]");
        else if(iphead[9] == IPPROTO_IGMP)
            printf("[IGMP]");
        else
            printf("[OTHERS]");

        printf(" PORT [%d]->[%d]\n", (iphead[20]<<8|iphead[21]), (iphead[22]<<8|iphead[23]));
    }
    close(sock);
    exit(0);
}
