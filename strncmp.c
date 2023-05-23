#include "main.h"
/**
 * _strncmp - compares two strings up to n characters
 * @s1: the first string
 * @s2: the second string
 * @n: number of characters to compare
 *
 * Return: the difference
 */

int _strncmp(char *s1, char *s2, size_t n)
{
        size_t i;
        int diff;

        for (i = 0 ; i < n ; i++)
        {
                diff = s1[i] - s2[i];
                if (diff != 0)
                        break;
        }
        return (diff);
}
