#include <stdio.h>
#include <stdarg.h>

int display(char *format, ...);

int main(void)
{
    display("%d : %d : %f \n", 10, 20, 30.0);  
    display("%s \n", "test");  
    return 0;
}

int display(char *format, ...) 
{
    va_list ap;
    char *p, *sval;
    int ival;
    float fval;

    va_start(ap, format);
    for(p=format; *p ; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("integer:%d ", ival);
                break;

            case 'f':
                fval = va_arg(ap, double);
                printf("float:%f  ", fval);
                break;

            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    printf("string:%c  ", *sval);
                break;

            default:
                printf("unknown type: ");
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

