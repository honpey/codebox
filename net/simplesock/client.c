#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<errno.h>

#define MAXLINE 4096
#define SER_PORT 8000

int main(int argc,char *argv[]){


    struct sockaddr_in servaddr;
    char buf[MAXLINE];

    int sockfd,n;
    char *str;
    char tt[5];

    //if(argc != 2){
       // fputs("usage: ./client message \n ",stderr);
       // exit(1);
    //}

    //str = argv[1];

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);
    servaddr.sin_port = htons(SER_PORT);

    if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0){
            printf("connet error:%s\n",strerror(errno));
        }

    while(1){
        
        memset(buf,0,MAXLINE);
		for (int j = 0; j < MAXLINE; j++) {
			buf[j]='a'+(j%26);
		}

        printf("client connet server ...\n");
        n = read(STDIN_FILENO,buf,MAXLINE);
        for(int i=0;i<5;i++){
                tt[i] = buf[i];
            }
        if(strcmp(tt,"exit1") == 0){
            printf("exit server connect \n");
            close(sockfd);
            return 0;
        }

		int i = 0;
		while(i++ < 100000){ // 4096*10000 = 40M
        	write(sockfd,buf,n);
			printf("i:%d\n", i);
		}

		printf("writeDone");
        if(strcmp(tt,"exit1") == 0){
            printf("exit server connect \n");
            close(sockfd);
            return 0;
        }

        n = read(sockfd,buf,MAXLINE);


        printf("Response from server:\n");
        write(STDOUT_FILENO,buf,n);
        printf("\n");
    }
    
    close(sockfd);
    return 0;

}
