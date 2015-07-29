#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("yell");
        return 1;
    }
    int key = atoi(argv[1]);
    // printf("What do you want to encrypt:");
    string str_to_encrypt = GetString();
     
    for(int i = 0; i < strlen(str_to_encrypt); i++)
    {
        if (str_to_encrypt[i] >= 'a' && str_to_encrypt[i] <= 'z')
        { 
            if (str_to_encrypt[i] + key % 26 <= 'z') 
                printf("%c",str_to_encrypt[i] + key % 26);
            else
                printf("%c",str_to_encrypt[i] + key % 26 - 26);
        }
        else if  (str_to_encrypt[i] >= 'A' && str_to_encrypt[i] <= 'Z') 
        {
            if (str_to_encrypt[i] + key % 26 <= 'Z') 
                printf("%c",str_to_encrypt[i] + key % 26);
            else
                printf("%c",str_to_encrypt[i] + key % 26 - 26);
        }
        else
        {
            printf("%c",str_to_encrypt[i]);
        }
    }
    printf("\n");
    return 0;
}
