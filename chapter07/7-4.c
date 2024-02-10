#include <stdio.h>
#include <stdarg.h>

void miniscanf(char *fmt, ...){
    va_list ap;
    char *p;
    int ival;
    va_start(ap, fmt);
    for (p = fmt; *p; p++){
        if (*p != '%'){
            continue;
        }
        switch (*++p){
            case 'd':
                ival = va_arg(ap, int);
                scanf("%d", &ival);
                break;
        }
    }
}
