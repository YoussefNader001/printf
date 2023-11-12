#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            // Handle format specifier
            format++;
            switch (*format) {
                case 'c':
                    // Print a character
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    // Print a string
                    {
                        const char *str = va_arg(args, const char *);
                        while (*str) {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    // Print a percent sign
                    putchar('%');
                    count++;
                    break;
                default:
                    // Invalid format specifier, just print it
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            // Regular character, print it
            putchar(*format);
            count++;
        }

        // Move to the next character in the format string
        format++;
    }

    va_end(args);

    return count;
}

int main() {
    _printf("Hello, %s! The answer is %d%c\n", "world", 42, '%');
    return 0;
}
