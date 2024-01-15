#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jeux_Pendu.h"

int randomw(int maxnbr);

int pickaword(char *pickletter)
{
    FILE* words = NULL;
    words = fopen("Nbrwords.txt", "r");
    int nb_mots = 0, Nbwordchoosed = 0;
    int car = 0;

    if (words == NULL)
    {
        printf("Impossible to open any file");
        return 0;
    }

    do
    {
        car = fgetc(words);
        if(car == '\n')
        {
            nb_mots++;
        }
    }while(car != EOF && car != '\n');

    Nbwordchoosed = randomw(nb_mots);
    rewind(words);

    while(Nbwordchoosed > 0);
    {
        car = fgetc(words);
        if(car == '\n')
            nb_mots--;
    }

    fgets(pickletter, 100, words);

    pickletter[strlen(pickletter) - 1] = '\0';

    fclose(words);

    return 1;
}

int randomw(int maxnbr)
{
    srand(time(NULL));
    return rand() % maxnbr;
}