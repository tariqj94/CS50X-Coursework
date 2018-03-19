#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{

//To get a credit card number we need to use the "long long" data type that accepts up to 64 bits from the user.

    long long ccnum, cc0, x0;
    int ccsum, x0prod, sum;

    do

    {
        printf("Credit card number:\n");
        ccnum = get_long_long();
    }

    while (ccnum < 0 || ccnum == 0);

//First we must sum every digit starting with the last.

//The below code shifts the position of the 2nd to last digit to after the decimal point by dividing the CC# by 100.

//We take % 10 (modulus 10) of the CC# to get the last position number, then add (ccnum/100)%10 to the first result and repeat.

    for (cc0 = ccnum, ccsum = 0; cc0 > 0; cc0 /= 100)

        ccsum += cc0 % 10;

//Now we double every digit starting with the 2nd to last - this is why we do /10 here, to get the 2nd to last digit.

    for (x0 = ccnum / 10, x0prod = 0; x0 > 0 ; x0 /= 100)

    {

//The below conditional statement is intended to handle cases when the amount we have on the other side of the decimal point - the
//result of the modulus - is 10 or larger.  We have to add the numbers individually - if we get 14, we must + 1 + 4 = +5, not +14.

        if (2 * (x0 % 10) > 9)

        {
            x0prod += (2 * (x0 % 10)) / 10;
            x0prod += (2 * (x0 % 10)) % 10;
        }

        else

            x0prod += 2* (x0 % 10);

    }
    sum = ccsum + x0prod;

//Now we'll check the validity of the CC# and it's brand affiliation.

    if (sum % 10 == 0)

    {
        if ((ccnum >= 340000000000000 && ccnum < 350000000000000) || (ccnum >= 370000000000000 && ccnum < 380000000000000))
            printf("AMEX\n");
        else if (ccnum >= 5100000000000000 && ccnum < 5600000000000000)
            printf("MASTERCARD\n");
        else if ((ccnum >= 4000000000000 && ccnum < 5000000000000) || (ccnum >= 4000000000000000 && ccnum < 5000000000000000))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else

        printf("INVALID\n");

    return 0;
}