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
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

size_t	ft_strlen(const char *line)
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;

	if (nmemb && ((nmemb * size) / nmemb) != size)
		return (NULL);
	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	bzero(buff, nmemb * size);
	return (buff);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	srclen;
	unsigned int	count;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	count = 0;
	while (count < size - 1 && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (srclen);
}

char	*extend_line(char *line, char *buffer)
{
	int	idx;

	if (!buffer || !ft_strlen(buffer))
		return (line);
	idx = 0;
	while (buffer[idx] && buffer[idx] != '\n')
		idx++;
	if (line)
	{
		line = ft_realloc(line, ft_strlen(line) + idx + 2);
		ft_strlcat(line, buffer, ft_strlen(line) + idx + 2);
	}
	else
	{
		line = (char *)calloc(idx + 2, sizeof(char));
		ft_strlcpy(line, buffer, idx + 2);
	}
	return (line);
}
