#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd[2];
    int p = pipe(fd);
    char s1[10];
    if (p < 0)
        printf("errore");
    else
    {
        int pid = fork();
        if (pid > 0) // padre
        {
            close(fd[0]);
            
            printf("inserire primo messaggio \n");
            scanf("%s", s1);
            
            write(fd[1], s1, sizeof(s1));
            
            printf("inserire secondo messaggio \n");
            scanf("%s", s1);
            
            write(fd[1], s1, sizeof(s1));
        }
        else
        {
            close(fd[1]);

            read(fd[0], s1, sizeof(s1));
            printf("primo messaggio inserito dal padre %s \n", s1);
            
            read(fd[0], s1, sizeof(s1));
            printf("secondo messaggio inserito dal padre %s \n", s1);
        }
    }
}