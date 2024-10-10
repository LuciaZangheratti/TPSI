#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 20
#define NUMCAT 5
typedef struct
{
    char titolo[DIM];
    char autore[DIM];
    int annoP;
    float prezzo;

} Libro;

typedef struct
{
    char categoria[40];//nome categoria
    Libro libri[6];
    int numero_libri;
} Categoria;

Categoria categorie[NUMCAT];
char nomeCategoria[30];

void Visualizza(char nomeCategoria)
{
    for (int i = 0; i < NUMCAT; i++)
    {
        if (strcmp(categorie[i].categoria, nomeCategoria) == 0)
        {
            printf("Libri nella categoria '%s':\n", nomeCategoria);
            for (int j = 0; j < categorie[i].numero_libri; j++)
            {
                Libro libro = categorie[i].libri[j];
                printf("Titolo: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
                       libro.titolo, libro.autore, libro.annoP, libro.prezzo);
            }
            return;
        }
    }
    printf("Categoria non trovata.\n");
}

void Cerca_libro(char *titolo)
{
    for (int i = 0; i < NUMCAT; i++)
    {
        for (int j = 0; j < categorie[i].numero_libri; j++)
        {
            Libro libro = categorie[i].libri[j];
            if (strcmp(libro.titolo, titolo) == 0)
            {
                printf("Libro trovato: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
                       libro.titolo, libro.autore, libro.annoP, libro.prezzo);
                return;
            }
        }
    }
    printf("Libro non trovato.\n");
}

int main()
{
    
    FILE *f;
    if (f = fopen("liberria_libri.csv", "r") == NULL)
    {
        printf("Errore apertura del file");
        return -1;
    }
    return 0;

    char tit[30];
    int scelta;

    do
    {
        printf("\nMenu:\n");
        printf("1. Visualizza libri per categoria\n");
        printf("2. Cerca libro per titolo\n");
        printf("3. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
            printf("Inserisci la categoria da ricercare:narrativa/scienza/romanzo/letteratura: \n");
            scanf("%s",nomeCategoria);
            Visualizza(nomeCategoria);
                break;
            case 2:
                printf("Inserisci il titolo del libro da cercare: ");
                Cerca_libro(tit);
                break;
            case 3:
                printf("Uscita dal programma...\n");
                break;
            default:
                printf("Opzione non valida. Riprova.\n");
        }

    }while(scelta != 3);
}