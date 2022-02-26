#include <cs50.h>
#include <stdio.h>

int main(void){
    string username = get_string("Entry your username: ");
    printf("Hello, %s\n", username);
}