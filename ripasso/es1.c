//passaggio di stringhe tra due processi, padre e figlio tramite una pipe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int p;

int main()
{
    int fd[2];  // fd[0] per read , fd[1] per write
    char s[20]; // stringa da passare da padre a figlio
    pipe(fd);   // pipe

     p = fork();

    if (p < 0)
    {
        printf("\nErrore nella creazione del figlio");
        exit(1);
    }
    if (pipe(fd) < 0)
    {
        printf("\nErrore creazione pipe");
        exit(-1);
    }
    if (p > 0)//padre
    { 
        close(fd[0]);   
        printf("inserire messaggio: %s\n", s);
        scanf("%s", s);
        write(fd[1], s, sizeof(s)); // scrivo nella pipe s
    }
    else//filgio
    {        
        close(fd[1]); // chiudo la pipe in scrittura
        read(fd[0], s, sizeof(s));
        printf("comunicato questo: %s \n", s);
    }

    return 0;
}