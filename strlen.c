#include "main.h"
/**
 * _strlen - This function calculates the lenght of a string
 * @s: is the string to be measured
 * Return:the length of the string
 */

int _strlen(char *s)
{
        int count;

        for (count = 0 ; *(s + count) != '\0' ; count++)
                ;
        return (count);
}
