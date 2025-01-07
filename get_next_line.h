#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
/*Includes*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <bsd/string.h>

/*Defining buffer_size and other macros*/
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 23
#endif

#define NEWL '\n'

/*Prototypes*/
char *get_next_line(int fd);

/*Utils prototypes*/
size_t	ft_strlen(char *line);
char	*ft_realloc(char *line, int size);
char	*ft_strchr(const char *s, int c);
#endif
