#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string with conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move to the next character after '%' */
            switch (*format)
            {
            case 'c':
                count += _putchar(va_arg(args, int));
                break;
            case 's':
                count += _puts(va_arg(args, char *));
                break;
            case '%':
                count += _putchar('%');
                break;
            default:
                count += _putchar('%');
                count += _putchar(*format);
                break;
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}
