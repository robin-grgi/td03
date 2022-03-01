#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>

int main(int argc, char const *argv[])
{
    while (1)
    {
        char cwd[PATH_MAX + 1];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            char *cmd;
            printf("%s/ ", cwd);
            scanf("%s", cmd);
            system(cmd);
        }
        else
        {
            perror("getcwd error");
            return 1;
        }
    }
}
