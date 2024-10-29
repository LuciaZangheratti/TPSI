// Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server
// riceve in input 1 stringa e, dopo aver effettuato gli eventuali ed opportuni
// controlli (se necessari), rispedisce al Client il messaggio se è palindroma oppure non lo è.

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

char palindroma(char *str)
{
    int i = 0;
    for (i ; i < strlen(str) / 2; i++)
    {
        if (str[i] != str[strlen(str) - 1 - i])
            break;
    }
    if (i < strlen(str) / 2)
        printf("\nLa parola non è palindroma\n");
    else
        printf("\nLa parola è palindroma\n");

    return 0;
}

int main()
{
    struct sockaddr_in scambio;

    scambio.sin_family = AF_INET;
    scambio.sin_addr.s_addr = htonl(INADDR_ANY);
    scambio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(scambio);

    char str[DIM];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socketfd, (struct sockaddr *)&scambio, sizeof(scambio));

    listen(socketfd, 10);

    for (;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&scambio, &fromlen);

        read(soa, str, sizeof(str));
        printf("\nStringa ricevuta: %s\n", str);

        palindroma(str);

        send(soa, str, strlen(str), 0);
        printf("\nInviato al client: %s\n", str);

        close(soa);
    }
    return 0;
}