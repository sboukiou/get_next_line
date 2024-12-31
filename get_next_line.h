#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <bsd/string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 23
#endif

char *get_next_line(int fd);
char	*ft_strdup(char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *line);
char	*ft_realloc(char *line, int size);
#endif
