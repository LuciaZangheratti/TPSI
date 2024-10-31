//CLIENT

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


int main(int argc, char **argv)
{
    struct sockaddr_in scambio;

    scambio.sin_family = AF_INET;
    scambio.sin_addr.s_addr = htonl(INADDR_ANY);
    scambio.sin_port = htons(SERVERPORT);
    char str1[DIM]; // Stringa da inviare

    int socketfd; // identificatore della socket
    char c;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&scambio, sizeof(scambio));

    printf("Inserisci la stringa\n");
    scanf("%s", str1);
    getchar();
    printf("Inserisci carattere da ricercare\n");
    scanf("%c", &c);
    
    write(socketfd, str1, sizeof(str1)); // scrivo nella socket
    write(socketfd, &c, sizeof(c));

    close(socketfd);
    return 0;
}
