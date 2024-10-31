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

void ordina(char *str)
{
    char temp;

    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for (int j = 0; j < strlen(str) - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto; 
    
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM];
    
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
   
    listen(socketfd, 10); 

    for (;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
      
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        
        read(soa, str, sizeof(str));
        printf("Stringa ricevuta: %s\n", str);
        ordina(str);
        printf("Stringa ordinata: %s\n", str);
        close(soa);
    }
    return 0;
}
