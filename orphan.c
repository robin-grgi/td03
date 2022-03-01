#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

    switch (fork())
    {
    case -1:
        perror("fork");
        exit(1);
    case 0:
        for (int i = 0; i < 5; i++)
        {
            sleep(1);
            printf("My father is %d\n", getppid());
        }
        exit(0);
    default:
        printf("I am the father %d\n", getpid());
        exit(0);
    }
    return 0;
}
