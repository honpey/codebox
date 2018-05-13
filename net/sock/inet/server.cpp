#include <sys/types.h>    
#include <sys/socket.h>    
#include <sys/un.h>    
#include <netinet/in.h>
#include <unistd.h>    
#include <stdlib.h>    
#include <stdio.h>    
    
int main()
{    
  /* delete the socket file */    
  unlink("server_socket");

  /* create a socket */
  int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd < 0) {
      printf("Fail to create sock:%d\n", server_sockfd);
      return -1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port=htons(10943);

  /* bind with the local file */
  if(bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      printf("Fail to bind\n");
      return -1;
  };

  /* listen */
  listen(server_sockfd, 5);

  char ch;    
  int client_sockfd;    
  struct sockaddr_un client_addr;    
  socklen_t len = sizeof(client_addr);    
  while(1)    
  {    
    printf("server waiting:\n");    
        
    /* accept a connection */    
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &len);    
        
    /* exchange data */    
    read(client_sockfd, &ch, 1);    
    printf("get char from client: %c\n", ch);    
    ++ch;    
    write(client_sockfd, &ch, 1);    
        
    /* close the socket */    
    close(client_sockfd);    
  }    
      
  return 0;    
}    
