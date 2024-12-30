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
