#include "get_next_line.h"
#include <stdio.h>

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

	if (!buffer)
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			line_read;
	char	*temp;
	char	*new_buffer;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	line = NULL;
	if (!buffer)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	if (buffer && read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	while (ft_strchr(buffer, '\n') == NULL)
	{
		line = extend_line(line, buffer);
		if (!line)
			return (free(buffer), NULL);
		line_read = read(fd, buffer, BUFFER_SIZE);
		if (line_read <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (line);
		}
		buffer[line_read] = '\0';
	}
	line = extend_line(line, buffer);
	if (!line)
		return (free(buffer), NULL);
	temp = ft_strchr(buffer, '\n');
	if (temp)
	{
		new_buffer =  (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
		strcpy(new_buffer, temp + 1);
		free(buffer);
		buffer = new_buffer;
	}
	return (line);
}

