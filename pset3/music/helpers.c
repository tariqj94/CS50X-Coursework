// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
//int main(int argc, string argv[])
//{
  //  printf("%d\n", argc);
    //string fraction = argv[1];
    //int x = fraction[0] - '0';
    //int y = fraction[2] - '0';
    //int eighths = x*8/y;
    //printf("%d\n", eighths);
    //return 0;
//}

int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int eighths = (x * 8) / y;
}

// Calculates frequency (in Hz) of a note
//int frequency(string note)
//{
    // TODO
  //  return 0;
//}

// Determines whether a string represents a rest
//bool is_rest(string s)
//{
    // TODO
  //  return 0;
//}
