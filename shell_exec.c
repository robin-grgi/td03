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
        switch (fork())
        {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            execlp("who", "", NULL);
            exit(0);
        default:
            execlp("cd", "", NULL);
            break;
        }        
    default:
        execlp("ls", "-ls", NULL);
        break;
    }
    return 0;
}
