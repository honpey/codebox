#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int pid = 0;
    char buf[4096];
    int i = 0;
    for (i = 0; i < 4096; i++) {
        buf[i] = 'A'+i%23;
    }
//    setuid(getuid());
    int fdGuest = open("./fileGuest", O_RDWR, NULL);
    if (fdGuest < 0) {
        printf("fail to open fileGuest\n");
        exit(0);
    }
    write(fdGuest, buf, 4096);
    close(fdGuest);

    int fdHon = open("./fileHon", O_RDWR, NULL);
    if (fdHon < 0) {
        printf("fail to open ./fileHon\n");
        exit(0);
    }
    write(fdHon, buf, 4096);
    close(fdHon);

    /*
    int fdGuest2 = open("./fileGuest2", O_RDWR, NULL);
    if (fdGuest2< 0) {
        printf("fail to open ./fileGuest2\n");
        exit(0);
    }
    */

    kill(32614, 9); 
    pid = fork();
    if (pid > 0) {
        printf("child: %d\n", getpid());
    } else {
        printf("parent: %d\n", getpid());
    }
    
    while(1);
    return 0;
}
