#include "get_next_line.h"
#include <stdio.h>

char	*get_full_buffer(char *buffer, int	fd)
{
	int		lines_read;

	while (ft_strchr(buffer, NEWL) == NULL)
	{
		buffer = ft_realloc(buffer, (ft_strlen(buffer) + BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);

		lines_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
		if (lines_read < 1)
			return (buffer);
	}
	return (buffer);
}

char    *reset_buffer(char *buffer)
{
        char    *temp;
        char    *new_buffer;

		new_buffer = NULL;
        if (!ft_strlen(buffer))
                return (buffer);
        temp = ft_strchr(buffer, '\n');
        if (temp && temp[1] != '\0')
		{
			new_buffer = ft_calloc((size_t)(BUFFER_SIZE) + 1, sizeof(char));
			ft_strlcpy(new_buffer, temp + 1, ft_strlen(temp + 1) + 1);
		}
        free(buffer);
        buffer = NULL;
        return (new_buffer);
}


#define MAX_FD 1025

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1025];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd > 1023)
		return (NULL);
	buffer[fd] = get_full_buffer(buffer[fd], fd);
	if (!buffer[fd] || !ft_strlen(buffer[fd]))
		return (free(buffer[fd]), buffer[fd] =  NULL, NULL);
	line = extend_line(buffer[fd]);
	buffer[fd] = reset_buffer(buffer[fd]);

	if (!ft_strlen(buffer[fd]))
		free(buffer[fd]), buffer[fd] =  NULL;
	return (line);
}
