#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("yell\n");
        return 1;
    }
    string keyword = argv[1];
    for(int i = 0, n = strlen(keyword); i < n ; i++)
    {
        if (keyword[i] < 'A' || (keyword[i] > 'Z' && keyword[i] < 'a') || keyword[i] > 'z')
        {
            printf("yell\n");
            return 1;
            }
    }

    // printf("What do you want to encrypt:");
    string str_to_encrypt = GetString();
    int keyword_index = 0;
    int len_keyword = strlen(keyword);
      
    for(int i = 0; i < strlen(str_to_encrypt); i++)
    {
        if (str_to_encrypt[i] >= 'a' && str_to_encrypt[i] <= 'z')
        {   
            int key = tolower(keyword[keyword_index]) - 'a';
            if (keyword_index < len_keyword - 1)
            {
                keyword_index++;
                }
            else
            {
                keyword_index = 0;
                }
            

            if (str_to_encrypt[i] + key % 26 <= 'z')
            {   
                printf("%c",str_to_encrypt[i] + key % 26);
            }
            else
                printf("%c",str_to_encrypt[i] + key % 26 - 26);
        }
        else if  (str_to_encrypt[i] >= 'A' && str_to_encrypt[i] <= 'Z') 
        {
            int key = tolower(keyword[keyword_index]) - 'a';
            if (keyword_index < len_keyword - 1)
            {
                keyword_index++;
                }
            else
            {
                keyword_index = 0;
                }
            
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
