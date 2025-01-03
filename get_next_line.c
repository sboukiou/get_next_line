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
			new_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			ft_strlcpy(new_buffer, temp + 1, ft_strlen(temp + 1) + 1);
		}
        free(buffer);
        buffer = NULL;
        return (new_buffer);
}



char	*get_next_line(int file_d)
{
	char		*line;
	static char	*buffer;

	if (file_d < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = get_full_buffer(buffer, file_d);
	if (!buffer)
		return (NULL);
	line = extend_line(buffer);
	buffer = reset_buffer(buffer);

	if (!ft_strlen(buffer))
		free(buffer), buffer =  NULL;
	return (line);
}
