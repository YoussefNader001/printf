#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buff_ind = 0;

va_list list;

char buffer[BUFF_SIZE];

if (format == NULL)

return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)

{

if (format[i] != '%')

{

buffer[buff_ind++] = format[i];

if (buff_ind == BUFF_SIZE)

print_buffer(buffer, &buff_ind);

/* write(1, &format[i], 1);*/

printed_chars++;

}

else

{

print_buffer(buffer, &buff_ind);

flags = get_flags(format, &i);

width = get_width(format, &i, list);

precision = get_precision(format, &i, list);

size = get_size(format, &i);

++i;

printed = handle_print(format, &i, list, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



print_buffer(buffer, &buff_ind);



va_end(list);



return (printed_chars);

}



/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{

if (*buff_ind > 0)

write(1, &buffer[0], *buff_ind);



*buff_ind = 0;

}
#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++; /* Move to the next character after '%' */

            switch (*ptr)
            {
            case 'c':
                c = va_arg(args, int);
                count += write(1, &c, 1);
                break;
            case 's':
                str = va_arg(args, char *);
                count += write(1, str, _strlen(str));
                break;
            case '%':
                count += write(1, "%", 1);
                break;
            default:
                count += write(1, "%", 1);
                count += write(1, &(*ptr), 1);
            }
        }
        else
        {
            count += write(1, &(*ptr), 1);
        }
    }

    va_end(args);
    return count;
}

/**
 * _strlen - Calculate the length of a string
 * @s: Input string
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }

    return len;
}
