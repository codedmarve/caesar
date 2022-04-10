#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //checking if argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //iterating through every character of argv[1]
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        //checking if each character in argv[1] is a digit
        if (!isdigit(argv[1][i]))
        {
            printf("error\n");
            return 1;
        }
    }

    //converting the string or character to integer
    int key = atoi(argv[1]);

    //ensuring key is greater that 0
    if (key < 0)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //if key is greater that 0, get input from user
        string text = get_string("Plaintext: ");

        //notice there is no "\n". The encrypted text will come infront of ciphertext
        printf ("Ciphertext: ");

        //iterating through the input of user
        for (int i = 0, text_length = strlen(text); i < text_length; i++)
        {
            //if its a lowercase character, programme should encrypt
            if (islower(text[i]))
            {
                printf("%c", (((text[i] - 97) + key) % 26) + 97);
            }
            //if its a uppercase character, programme should encrypt
            else if(isupper(text[i]))
            {
                printf("%c", (((text[i] - 65) + key) % 65) + 65);
            }
            //if not, programme should do nothing
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }
    return 0;
}