// Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server
// riceve in input 1 stringa e un carattere,e dopo aver effettuato gli eventuali ed opportuni
// controlli (se necessari), rispedisce al Client il numero di occorrenze del carattere nella stringa.

// SERVER
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 1313

int ConteggioCarattere(char *str, char c)
{
    int cont=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            cont++;
    }
    return cont;
}

int main()
{
    struct sockaddr_in scambio;

    scambio.sin_family = AF_INET;
    scambio.sin_addr.s_addr = htonl(INADDR_ANY);
    scambio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(scambio);

    char str[DIM];
    int cont;
    char c;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socketfd, (struct sockaddr *)&scambio, sizeof(scambio));

    listen(socketfd, 10);

    for (;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&scambio, &fromlen);

        read(soa, str, sizeof(str));
        read(soa, &c, sizeof(c));

        printf("\nStringa ricevuta: %s\n", str);

        cont = ConteggioCarattere(str, c);
        printf("La lettera %c è presente: %d",c,cont);

        printf("\nInviato al client: %s\n", str);

        close(soa);
    }
    return 0;
}