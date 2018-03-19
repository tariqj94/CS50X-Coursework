#include <cs50.h>
#include <stdio.h>

bool is_triangle(float a, float b, float c);

bool is_trinagle(float a, float b, float c)
{
    //First we need to check that all values are positive
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    //Then we need to make sure no two sides are shorter than the third
    if(a + b <=c || a + c <=b || b + c <=a)
    {
        return false;
    }

    //If both if statements are passed we have ourselves a triangle!
    return true;
}