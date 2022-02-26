#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_key_requirements(string key);
int get_index_from_string(char c, string s);


int main(int argc, string argv[])
{
    // Checking arguments from command-line
    if (argc != 2)
    {
        printf("USAGE: Usage: ./substitution key\n");
        return 1;
    }

    // Check key requirements
    string key = argv[1];
    if (check_key_requirements(key))
    {
        return 1;
    }

    // Getting message to encrypt
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string message = get_string("plaintext: ");
    string cipher = message;

    // Generating encrypted message
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        char c = message[i];
        int alphabet_index = get_index_from_string(message[i], alphabet);

        // Encrypt only alphanumeric characters
        if (!isalpha(c))
        {
            cipher[i] = c;
        }
        else if (isupper(c))
        {
            cipher[i] = toupper(key[alphabet_index]);
        }
        else
        {
            cipher[i] = tolower(key[alphabet_index]);
        }
    }

    printf("ciphertext: %s\n", (string) cipher);
    return 0;
}

/*
* Get index of char c in string s
* if s doesnt contain c return -1
*/
int get_index_from_string(char c, string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (toupper(c) == toupper(s[i]))
        {
            return i;
        }
    }

    return -1;
}

/*
* Key must meet the following requirements
* 1. 26 letters
* 2. All letters are alphabetical
* 3. No repeating letters
*/
int check_key_requirements(string key)
{
    int key_length = strlen(key);
    // 1. 26 letters
    if (key_length != 26)
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }

    for (int i = 0; i < key_length; i++)
    {
        // 2. All letters are alphabetical
        if (!isalpha(key[i]))
        {
            printf("All letters in key must be alphabetical\n");
            return 1;
        }

        // 3. No repeating letters
        for (int j = key_length - 1; j > i; j--)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key can't conatin repeating letters\n");
                return 1;
            }
        }
    }

    return 0;
}