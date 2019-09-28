#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>       /* basic system data types */
#include<sys/socket.h>      /* basic socket definitions */
#include<netinet/in.h>      /* sockaddr_in{} and other Internet defns */
#include<arpa/inet.h>       /* inet(3) functions */
#include<sys/epoll.h>       /* epoll function */
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>


int main(int argc,char*argv[])
{
    int listenfd,connfd;
    struct sockaddr_in cliaddr,servaddr;
    int queuelen=5;

    if(argc!=2){
        puts("usage# ./aworker listenqueuelen");
        exit(0);
    }   
    queuelen=atoi(argv[1]);

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(2989);
    
    bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
    listen(listenfd,queuelen);
    sleep(60); //将这个注释，会出现另一种情况哟~~  
    while(1)
    {
        connfd = accept(listenfd,NULL,0);
        if(connfd == -1)
        {
            perror("accept error");
            continue;
        }
        puts("new connection...");
    }
    return 0;
}
