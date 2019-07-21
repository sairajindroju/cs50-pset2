#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int getK(int lettersCiphered, string k);

int main(int argc, string argv[])
{	
    if (argc != 2)
    {
        printf("Invalid\n");
        return 1;
    }
    printf("Plaintext: ");
    string a = argv[1];
    for (int i = 0, length = strlen(a); i < length; i++)
    {
        if (!isalpha(a[i]))
        {
            printf("Invalid\n");
            return 1;
        }
    }
    string s = get_string();
    int lettersCiphered = 0;
    printf("ciphertext: ");
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char c = s[i];
        if (isupper(c))
        {
            char newC = (((c - 65) + getK(lettersCiphered,a)) % 26) + 65;
            printf("%c", newC);
            lettersCiphered++;
        }
        else if(islower(c))
        {
            char newC = (((c - 97) + getK(lettersCiphered,a)) % 26) + 97;
            printf("%c", newC);
            lettersCiphered++;
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

int getK(int lettersCiphered, string a)
{
    int length = strlen(a);
    return tolower(a[lettersCiphered % length]) - 97;
}