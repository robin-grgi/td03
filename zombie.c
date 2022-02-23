#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define P 10
#define N 10

int main(int argc, char const *argv[])
{
    int pid;
    int cpt = 1;
    switch (pid = fork())
    {
    case -1:
        perror("fork");
        exit(1);

    case 0:
        ++cpt;
        printf("[¬º-°]¬\n");
        sleep(1);
        exit(0);
    default:
        sleep(5);
        break;
    }
    return 0;
}
