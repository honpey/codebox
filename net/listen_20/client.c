//#include "client.h"
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

//void cli_hander(int sockfd,)

int main()
{
    int sockfd;
    int rc; 
    int cpid;
    struct sockaddr_in servaddr;
    
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);
    servaddr.sin_port = htons(2989);
    
    for(int i=0;i<20;i++)
    {   
        cpid = fork();
        if(cpid == 0)
        {   
            sockfd = socket(AF_INET,SOCK_STREAM,0);
            rc = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
            if(rc == -1) 
            {   
                perror("connect error");
                exit(0);
            }   
            printf("pid#%d connected...\n",getpid());
            sleep(3);
            close(sockfd);
            exit(0);
        }   
    }   

    while(1)
    {   
        cpid = wait(NULL);
        if(cpid==-1){
            perror("end of wait");
            break;
        }
        printf("pid#%d exit...\n",cpid);
    }
    return 0;
}
