#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

//The below program will take a non-negative integer no greater than 23 from the user and print a half-pyramid of that height

int main(void)
{

//This is an example of "do-while invalid" which whill repeat an operation as long as the while conidition is satisfied

    int height = 0;
    do
    {
        printf("Please input a positive, non-zero integer value no greater than 23, or 0 to end the program: \n");
        height = get_int();
    if(height == 0)
    {
        return 0;
    }
    }
    while (height < 1 || height > 23);

//The following section of code will print the pyramind with height specified by user above

    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < height - (i) - 1; a++)
        {
            printf(" ");
        }
        for (int b = 0; b <= i; b++)
        {
            printf("#");
        }
        printf("  ");
        for (int c = 0; c <= i; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
