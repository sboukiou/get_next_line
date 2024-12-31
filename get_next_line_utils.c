#include "get_next_line.h"
#include <fcntl.h>

char	*ft_realloc(char *line, int size)
{
	char	*new_line;
	int		i;
	new_line = (char *)malloc(sizeof(char) * size);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

char	*ft_strdup(char *str)
{
	char *buff;
	int	idx;

	if (!str)
		return (NULL);
	idx = 0;
	while (str[idx])
		idx++;
	buff = calloc(idx + 1, sizeof(char));
	if (!buff)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		buff[idx] = str[idx];
		idx++;
	}
	return (buff);
}

size_t	ft_strlen(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			return ((char *)(s + count));
		count++;
	}
	if ((unsigned char)c == 0)
		return ((char *)(s + count));
	return (NULL);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	count;

	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *)src);
	if (size == 0)
		return (srclen);
	count = 0;
	while (src[count] && destlen + count < size - 1)
	{
		dest[destlen + count] = src[count];
		count++;
	}
	dest[destlen + count] = '\0';
	if (size < destlen)
		return (size + srclen);
	return (destlen + srclen);
}
