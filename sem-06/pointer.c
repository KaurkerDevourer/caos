#include <stdio.h>

int main()
{

    char str[20] = "RandomString\n";

    // Pointer variable which stores
    // the starting address of
    // the character array str
    char* ptr = str;

    // While loop will run till 
    // the character value is not
    // equal to null character
    while (*ptr != '\0') {
        printf("%c", *ptr);
      
        // moving pointer to the next character.
        ptr++;
    }

    return 0;
}
