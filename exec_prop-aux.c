#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    printf("exec call pid : %d, argv[0] : %s", getpid(), argv[0]);
    return 0;
}