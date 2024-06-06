#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct
{
    char nome[20];
    char cognome[30];
} Persona;

void *stampaPersona(void* par)
{
    Persona *p2 = (Persona *)par;//converte il void in persona puntatore

    printf("\n%s\n", p2->nome);
    printf("%s\n", p2->cognome);
}
void *salvaPersona (void* par)
//scrive la struttura Persona nel file e poi chiude il file.
{
    FILE *file = fopen("studente.txt", "wb");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file");
        return NULL;
    }

    Persona *p3 = (Persona *)par;

    fwrite(p3, sizeof(Persona), 1, file);
    fclose(file);

    printf("Scrittura avvenuta\n");

    return NULL;
}

int main(int argc, char *argv[])
{
    Persona p1;
    pthread_t threadA, threadB;

    strcpy(p1.nome, argv[1]);
    strcpy(p1.cognome, argv[2]);

    void* sPuntatore = &p1;//converto la struct studente in void puntatore

    pthread_create(&threadA, NULL, &stampaPersona, sPuntatore);//crea threadA viene assegnato la stampa dei dati
    pthread_create(&threadB, NULL, &salvaPersona, sPuntatore);//crea threadB salva la struct dello studente salva i dati
    
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    return 0;
}