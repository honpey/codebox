#include <sys/types.h>    
#include <sys/socket.h>    
#include <sys/un.h>    
#include <unistd.h>    
#include <stdlib.h>    
#include <stdio.h>    
#include <netinet/in.h>
#include <arpa/inet.h>
int main()    
{    
  /* create a socket */    
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);    
  struct sockaddr_in addr;
  if (sockfd < 0) {
      printf("Fail to create socket:%d\n", sockfd);
      return -1;
  }

  bzero(&addr, sizeof(addr));

  addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.1.111"); //
    addr.sin_port = htons(20943);
  /*
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(7002);
    */
      
  /* connect to the server */    
  int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if(result == -1)    
  {    
    perror("connect failed: ");    
    exit(1);    
  }    
      
  /* exchange data */    
  char ch = 'A';    
//  while(1) {
  	write(sockfd, &ch, 1);    
	read(sockfd, &ch, 1);    
	printf("-- get char from server: %c\n", ch);    
  //  sleep(3);
 //}
      
  printf("hello world\n");
  /* close the socket */    
  close(sockfd);    
      
  return 0;    
}    
