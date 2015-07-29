#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float money;
    do
    {
        printf("How Much Change is Owed?\n");
        money = GetFloat();
    }
    while(money < 0);
    int cents = (int) round(money * 100);
   
    int coins = 0;
    while(cents != 0)
    {  
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
            }
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
            }
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
            }
        else
        {
            cents = cents - 1;
            coins++;
            }
        }
    printf("%d\n",coins); 
    }
