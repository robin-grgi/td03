#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    switch (fork()){
        case -1:
            perror("fork");
            exit(1);
        case 0:
            sleep(5);
            printf("Child : %d, ", getpid());
            exit(0);
        default:
            printf("Father : %d", getpid());
            wait(NULL);
            printf("\n");
            break;
    }
    execlp("./exec_prop-aux.exe", "exec_prop-aux", "coucou", NULL);
    printf("this line should not be printed\n");
    return 0;
}