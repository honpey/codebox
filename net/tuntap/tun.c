#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <linux/if_tun.h>
#include <stdlib.h>
#include <stdio.h>

int tun_alloc(int flags)
{

    struct ifreq ifr;
    int fd, err;
    char *clonedev = "/dev/net/tun";

    if ((fd = open(clonedev, O_RDWR)) < 0) {
        return fd;
    }
	memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = flags; // 按照ifr_flags初始化一个以太网设备

    if ((err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0) {
        close(fd);
        return err;
    }

    printf("Open tun/tap device: %s for reading...\n", ifr.ifr_name);

    return fd;
}

int main()
{

    int tun_fd, nread;
    char buffer[1500];

    /* Flags: IFF_TUN   - TUN device (no Ethernet headers)
     *        IFF_TAP   - TAP device
     *        IFF_NO_PI - Do not provide packet information
	 *        默认每个数据包传到用户空间时，都会加一个包头来保存包的信息，不包含包的信息
     */
    tun_fd = tun_alloc(IFF_TUN | IFF_NO_PI);

    if (tun_fd < 0) {
        perror("Allocating interface");
        exit(1);
    }

    while (1) {
        nread = read(tun_fd, buffer, sizeof(buffer)); //来看看这个ＴＵＮ设备怎么执行咯
        if (nread < 0) {
            perror("Reading from interface");
            close(tun_fd);
            exit(1);
        }
		// 这里是读，所以说肯定是是有人朝这个网卡写东西了

        printf("Read %d bytes from tun/tap device\n", nread);
    }
    return 0;
}
