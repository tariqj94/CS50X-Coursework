#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//We must take 2 arguments from the user in the command line - both the name of the program (./caesar) and the cipher key
//Since all arrays can only hold a single data type the cipher key will be passed from the user as a string (to match the program call)
//We'll convert it to an integer inside of the program

int main(int argc, string argv[])
{

//We must ensure that the user entered the right number of arguments

#define ARGS 2
    if (argc != ARGS)
    {
        printf("I'm sorry, you entered more or less than 2 arguments!  PEACE \n");
        return 1;
    }

//Here we convert the cipher key to an integer, using KEYPOS as the cypher key position in the array passed from the command line

#define KEYPOS 1
    int ckey = atoi(argv[KEYPOS]);

//Now we need to get the text to be enciphered from the user

    string plaintext = get_string("plaintext: ");

//Now we have to offset individual components of the plaintext by the amount specified earlier in the cipher key

    for (int i = 0, n = strlen(plaintext); i < n; i ++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 65 + ckey) % 26 + 65);
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 97 + ckey) % 26 + 97);
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}