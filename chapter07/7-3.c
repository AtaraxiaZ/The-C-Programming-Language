#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    char cval;
    unsigned int uval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        switch (*++p){
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'c':
                cval = va_arg(ap, int);
                putchar(cval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned int);
                printf("%u", uval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
