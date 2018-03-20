// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int eighths = (x * 8) / y;
    return eighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //We have to do a number of things to get this right.  We know that A4 = 440 is our starting point
    //For each octave up or down, we know that we multiply 440 by 2^octaves - so 2 octaves up is 4 * 440
    //Then we know that each letter will jump us up or down a certain number of semitones
    //We finally know that flat or sharp notes adjust by single semitones, up and down respectively

    //Now we have the octave of the note
    int octave = note[strlen(note) - 1];
    octave -= '0';

    //Now we have to get the letter of the note and offset by the proper amount
    double freq = 0.0;
    if (note[0] == 'A')
    {
        freq = 440.0;
    }
    else if (note[0] == 'B')
    {
        freq = 440.0 * (exp2 (2.0 / 12.0));
    }
    else if (note[0] == 'C')
    {
        freq = 440.0 * (exp2 (-9.0 / 12.0));
    }
    else if (note[0] == 'D')
    {
        freq = 440.0 * (exp2 (-7.0 / 12.0));
    }
    else if (note[0] == 'E')
    {
        freq = 440.0 * (exp2 (-5.0 / 12.0));
    }
    else if (note[0] == 'F')
    {
        freq = 440.0 * (exp2 (-4.0 / 12.0));
    }
    else if (note[0] == 'G')
    {
        freq = 440.0 * (exp2 (-2.0 / 12.0));
    }

    //Now we have to offset by the proper amount due to octaves
    for (int i = 0; i < abs(octave - 4); i++)
    {
        freq *= (exp2((octave - 4)/abs(octave - 4)));
    }

    //Offset by flats and sharps
    if (note[1] == '#')
    {
        freq *= (exp2 (1.0 / 12.0));
    }
    else if (note[1] =='b' || note[1] == 'B')
    {
        freq /= (exp2 (1.0 / 12.0));
    }
    int frequency = round(freq);
    return frequency;

}

//Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "", 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}
