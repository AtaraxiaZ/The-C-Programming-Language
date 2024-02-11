#include <fcntl.h>
#include <syscall.h>
#include <unistd.h>
#include <stdlib.h>
#define PERMS 0666

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 /* max #files open at once */

struct flags {
    unsigned int read : 1;
    unsigned int write : 1;
    unsigned int unbuf : 1;
    unsigned int eof : 1;
    unsigned int err : 1;
};

typedef struct _iobuf {
    int cnt; /* characters left */
    char *ptr; /* next character position */
    char *base; /* location of buffer */
    struct flags flag; /* mode of file access */
    int fd; /* file descriptor */
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ = 01, /* file open for reading */
    _WRITE = 02, /* file open for writing */
    _UNBUF = 04, /* file is unbuffered */
    _EOF = 010, /* EOF has occurred on this file */
    _ERR = 020 /* error occurred on this file */
};


int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((p)->flag.eof == 1)
#define ferror(p) ((p)->flag.err == 1)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >= 0 \
? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putcher(x) putc((x), stdout)

FILE *myfopen(char *name, char *mode){
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flag.read == 0 && fp->flag.write == 0)
            break;
    if (fp >= _iob + OPEN_MAX)
        return NULL;
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a'){
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    if (*mode == 'r') {
        fp->flag.read = 1;
        fp->flag.write = 0;
    }
    return fp;
}

int _fillbuf(FILE *fp)
{
    int bufsize;
    if (fp->flag.read == 1 && fp->flag.eof == 0 && fp->flag.err == 0)
        return EOF;
    bufsize = (fp->flag.unbuf) ? 1 : BUFSIZ;
    if (fp->base == NULL) /* no buffer yet */
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF; /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag.eof = 1;
        else
            fp->flag.err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
