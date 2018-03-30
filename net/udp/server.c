#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <string.h>  
  
void server(int sock){  
    char recvbuf[1024] = {0};  
    struct sockaddr_in peeraddr;  
    socklen_t peerlen;  
    int n;  
    while(1){  
        peerlen = sizeof(peeraddr);  
        memset(recvbuf, 0, sizeof(recvbuf));  
        n = recvfrom(sock, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *)&peeraddr, &peerlen);  
        if(n == -1){  
                perror("recvfrom");   
                exit(EXIT_FAILURE);   
        }else if(n > 0){  
            fputs(recvbuf, stdout);  
            sendto(sock, recvbuf, n, 0, (struct sockaddr *)&peeraddr, peerlen);  
        }  
    }  
    close(sock);  
}  
  
int main(void){  
        int sock;  
        if((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0){  
            perror("socket error");  
            exit(EXIT_FAILURE);  
        }  
        struct sockaddr_in servaddr;  
        memset(&servaddr, 0, sizeof(servaddr));  
        servaddr.sin_family = AF_INET;  
        servaddr.sin_port = htons(5188);  
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
      
        if(bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){  
            perror("bind error");  
            exit(EXIT_FAILURE);  
        }  
        server(sock);  
        return 0;  
}  
