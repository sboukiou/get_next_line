#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char	*ft_realloc(char *line, int size);
char *get_next_line(int fd);
#endif
