#include "main.h"

/**
 * _itoa - converts an integer to a string
 * @n: integer
 *
 * Return: integer converted to string
 */
char *_itoa(int n)
{
        char *buffer;
        int i, k, j, size, digit;

        i = 0;
        size = 0;

        for (k = n; k != 0; k = k / 10)
                size++;
        buffer = malloc((size + 1) * sizeof(char));
        if (buffer == NULL)
                return (NULL);
        for (k = size; k > 0; k--)
        {
                digit = n;
                for (j = k; j > 1; j--)
                        digit = digit / 10;
                digit = digit % 10;
                if (digit < 0)
                        digit = digit * -1;
                buffer[i++] = digit + 48;
        }
        buffer[i] = '\0';

        return (buffer);
}
