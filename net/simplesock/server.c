#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> 

#include<sys/socket.h>
#include<netinet/in.h>    //互联网地址族   定义数据结构sockaddr_in
#include<arpa/inet.h>

#include<ctype.h> 

#define MAXLINE 80
#define SER_PORT 8000

int main(void){

    struct sockaddr_in servaddr,cliaddr;
    socklen_t cliaddr_len;

    int listenfd,connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i,n;
    char tt[] = "exit1";
    char *bb;

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr)); 

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(SER_PORT);

    bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

    listen(listenfd,20);

    printf("Accepting connections ... \n ");
    while(1){

        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&cliaddr_len);
            
                                                                   
        printf("connfd:%d------\n",connfd);

        printf("received from %s at PORT %d \n",
                inet_ntop(AF_INET,&cliaddr.sin_addr,str,sizeof(str)),
                ntohs(cliaddr.sin_port));
        while(1){
            n = read(connfd,buf,MAXLINE);

            printf("%d\n", n);
            for(int i=0;i<5;i++){
                tt[i] = buf[i];
            }
            printf("tt:%s-----%d\n",tt,strcmp(tt,"exit1"));
            if(strcmp(tt,"exit1") == 0){
                close(connfd);
                printf("close:-----\n");
                break;
            }

            for(i=0; i < n; i++){
                buf[i] = toupper(buf[i]);
            }
            write(connfd,buf,n);
        }                                                                           
        
    }

    return 0;                       

}

