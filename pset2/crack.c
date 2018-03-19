#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <crypt.h>

#define _XOPEN_SOURCE

int main(int argc, string argv[])
{

#define ARGS 2
#define pwlen 4

//We must ensure that the user has included their hash as part of their function

    if (argc != ARGS)
    {
        printf("Usage: ./crack hash \n");
        return 1;
    }

//Now we want to store the salt of their password - the cypher key - capping it off with a \0 so the program knows the end of the string

    char salt[] = {argv[1][0], argv[1][1], '\0'};
    char pwalphabet[] = {"ABCDEFGHIJKLMNOPQRSTUXWXYZabcdefghijklmnopqrstuvwxyz"};

//Iterate over all possible passwords, encrypt it using salt from command line, see if it matches full hash from command line

    for (int i = 0; i < strlen(pwalphabet); i++)
    {
        char pwguess1[] = {pwalphabet[i], '\0'};
        if (strcmp(argv[1], crypt(pwguess1, salt)) == 0)
        {
            printf("%s\n", pwguess1);
            return 0;
        }

        for (int j = 0; j < strlen(pwalphabet); j++)
        {
            char pwguess2[] = {pwalphabet[i], pwalphabet[j], '\0'};
            if (strcmp(argv[1], crypt(pwguess2, salt)) == 0)
            {
                printf("%s\n", pwguess2);
                return 0;
            }

            for (int k = 0; k < strlen(pwalphabet); k++)
            {
                char pwguess3[] = {pwalphabet[i], pwalphabet[j], pwalphabet[k], '\0'};
                if (strcmp(argv[1], crypt(pwguess3, salt)) == 0)
                {
                    printf("%s\n", pwguess3);
                    return 0;
                }

                for (int l = 0; l < strlen(pwalphabet); l++)
                {
                    char pwguess4[] = {pwalphabet[i], pwalphabet[j], pwalphabet[k], pwalphabet[l], '\0'};
                    if (strcmp(argv[1], crypt(pwguess4, salt)) == 0)
                    {
                        printf("%s\n", pwguess4);
                        return 0;
                    }
                }
            }
        }
    }
}