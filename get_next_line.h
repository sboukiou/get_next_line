#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <bsd/string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12
#endif

#define NEWL '\n'

char *get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*extend_line(char *buffer);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *line);
char	*ft_realloc(char *line, size_t size);
#endif
