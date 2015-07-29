#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int height;
    do
    {
        printf("Height:");
        height = GetInt();
    }
    while(height > 23 || height < 0);
    int i;
    int j;    
    for(i = 0;i < height;i++)
    {
        for(j = 0;j <= height - 2 - i;j++)
        {
            printf(" ");
        }
        for(j = 0;j < 2 + i;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
