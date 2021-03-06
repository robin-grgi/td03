#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid;
    switch (pid = fork())
    {
    case -1:
        perror("fork");
        exit(1);

    case 0:
        printf("[¬º-°]¬\n");
        sleep(1);
        exit(0);
    default:
        sleep(5);
        wait(NULL);
        break;
    }
    return 0;
}
