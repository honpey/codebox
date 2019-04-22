#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
using namespace std;
int g_unreliable = 0;
int g_reliable = 0;
void signal_dispath(int signo)
{
	if(signo == SIGUSR1)
	{
		cout<<"receving signal SIGUSR1"<<endl;
		g_unreliable++;
	}
    else if (signo == SIGTERM) {
        cout<<"receving signal SIGTERM" <<endl;
    }
    else if (signo == SIGSTOP) {
        cout<<"receving signal SIGSTOP" <<endl;
    }
    else if (signo == SIGKILL) {
        cout<<"receving signal SIGKILL" <<endl;
    }
}
void output_myself()
{
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	cout<<"^^^^^^^ Hello World ^^^^^^^"<<endl;
	cout<<"^^^^^^^ I'm  LeoK   ^^^^^^^"<<endl;
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
int main(int argc, char** argv)
{
    printf("%d\n", getpid());
	if(argc != 1)
	{
		cout<<"this program need not paramter"<<endl;
		return 0;
	}
	/* 每个程序的信息需要打印 */
	output_myself();
	if(signal(SIGUSR1, signal_dispath) == SIG_ERR)
	{
		perror("register SIGUSR1 signal failed");
		return -1;
	}
	if(signal(SIGTERM, signal_dispath) == SIG_ERR)
	{
		perror("register SIGTERM signal failed");
		return -1;
	}
    /*
    if(signal(SIGTERM, SIG_IGN) == SIG_ERR) {
        perror("register SIGTERM signal failed");
        return -1;
    }
    */
    printf("loop------\n");
    char *args[] = {"./loop", NULL};
    execvp(args[0], args);
	return 0;
}

