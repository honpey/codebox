#include <sys/types.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
#include <string.h>  
      
void client(int sock){  
    struct sockaddr_in servaddr;  
    memset(&servaddr, 0, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_port = htons(5188);  
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
  
    int ret;  
    char sendbuf[1024] = {0};  
    char recvbuf[1024] = {0};  
    while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL){  
		for (int i = 0; i < 1; i++)
        	sendto(sock, sendbuf, strlen(sendbuf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));  
		printf("send down\n");
        /*
        ret = recvfrom(sock, recvbuf, sizeof(recvbuf), 0, NULL, NULL);  
        if(ret == -1){  
            perror("recvfrom");  
            exit(EXIT_FAILURE);  
        }  
        */
  
        memset(sendbuf, 0, sizeof(sendbuf));  
        memset(recvbuf, 0, sizeof(recvbuf));  
    }  
    close(sock);  
}  
  
int main(void){  
    int sock;  
    if((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0){  
        perror("socket");  
        exit(EXIT_FAILURE);  
    }  
    client(sock);  
    return 0;  
}  
