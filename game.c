#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "jeux_Pendu.h"

char printcharacter ()
{
    char charac = 0 ;

    while(charac != '\n')
    {
        charac = getchar();
        charac = toupper(charac);
    }

    return charac;
}

int win(int letterfound[], long wordsize)
{
    long i = 0;
    int player = 1;

    for(i = 0; i < wordsize; i++)
    {
        if(letterfound[i] == 0)
            player = 0;
    }
    return player;
}

int findletter (char letter, char secretword[], int letterfound[])
{
    long i = 0;
    int goodletter = 0;

    for(i = 0; secretword[i] != '\0'; i++)
    {
        if(letter == secretword[i])
        {
            goodletter = 1;
            letterfound[i] = 1;
        }
    }
    return goodletter;
}

int main()
{
    char letter = 0;
    char secretword[100] = {0};
    int *letterfound = NULL;
    long remainingtrial = 10;
    long i = 0;
    long wordsize = 0;

    printf("Welcome to the game pendu\n\n");
    if(!pickaword(secretword))
        exit(0);

    wordsize = strlen(secretword);

    letterfound = malloc(wordsize * sizeof(int));

    if(letterfound == NULL)
        exit(0);
    for(i = 0; i < wordsize; i++)
        letterfound[i] = 0;

    do
    {
        printf("\n\nYou are left with %ld trial \n", remainingtrial);
        printf("What is the secret word ?\n");

        for(i = 0; i < wordsize; i++)
        {
            if(letterfound[i])
                printf("%c", secretword[i]);
            else
                printf("*");
        }
        printf("Propose a letter\n");
        letter = printcharacter();

        if(!findletter(letter, secretword, letterfound))
        {
            remainingtrial--;
        }
    } while(remainingtrial > 0 && !win(letterfound, wordsize));

    if(win(letterfound, wordsize))
    {
        printf("\n\n You have won, the word is %s\n", secretword);
    }
    else
    {
        printf("\nYou have loss, the letter was %s\n", secretword);
    }

    free(letterfound);

    return 1;
}

