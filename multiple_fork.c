#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define P 10
#define N 10

int main(int argc, char const *argv[])
{
    int tabPID[P];
    int cpt = 1;
    for (int i = 0; i < P; i++)
    {
        switch (tabPID[i] = fork())
        {
        case -1:
            perror("fork");
            exit(1);

        case 0:
            for (int j = 0; j < N; j++)
            {
                ++cpt;
                printf("fils n°%d\n", i);
            }
            sleep(1);
            exit(0);
        default:
            break;
        }
    }
    
    for(int i = 0 ; i < P ; i++){
        wait(tabPID+i);
    }

    return 0;
}
