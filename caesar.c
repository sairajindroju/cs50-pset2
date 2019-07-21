#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{	
   if (argc != 2)
    {
        printf("error <key>\n");
        return 1;
    }
    int k = atoi(argv[1]);
    printf("plaintext: ");
    string s = get_string();
    printf("ciphertext: ");
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char c = s[i];
        if (isupper(c))
        {
            char newC = (((c - 65) + k) % 26) + 65;
            printf("%c", newC);
        }
        else if(islower(c))
        {
            char newC = (((c - 97) + k) % 26) + 97;
            printf("%c", newC);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}