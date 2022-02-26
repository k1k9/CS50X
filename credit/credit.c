#include <cs50.h>
#include <stdio.h>

bool checksum(long card_number);
int sum_number(int number);
int get_length(long number);

int main(void)
{
    // Getting input from user
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (!card_number);

    // Check checksum and card length
    int length = get_length(card_number);
    if (!checksum(card_number) || length < 13 || length > 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculate card provider
    long provider = card_number;
    for (int i = length; i > 2; i--)
    {
        provider /= 10;
    }

    // Return user information about card provider
    if (provider == 34 || provider == 37)
    {
        printf("AMEX\n");
    }
    else if (provider >= 51 && provider <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (provider >= 40 && provider <= 49)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

/*
* Checksum for credit card number
*/
bool checksum(long card_number)
{
    int even_sum = 0;
    int odd_sum = 0;
    int remainder;
    int iterator = 0;

    // Calculating sum of every other and every first digit
    while (card_number != 0)
    {
        iterator++;
        remainder = card_number % 10;
        card_number /= 10;

        // Getting every other digit by 2
        // starting from the number's second-to-last
        if (iterator % 2 == 0)
        {
            remainder *= 2;
            if (remainder > 9)
            {
                remainder = sum_number(remainder);
            }
            even_sum += remainder;
        }
        else
        {
            odd_sum += remainder;
        }
    }

    // Sum of all numbers
    if ((even_sum + odd_sum) % 10 == 0)
    {
        return true;
    }
    return false;
}
/*
* Convert two or more digit number into sum of this numbers
*/
int sum_number(int number)
{
    int remainder, result = 0;
    while (number != 0)
    {
        remainder = number % 10;
        number /= 10;
        result += remainder;
    }

    return result;
}
/*
* Getting length of number
*/
int get_length(long number)
{
    int length = 0;

    // Calculate the card length
    while (number != 0)
    {
        length++;
        number /= 10;
    }

    return length;
}