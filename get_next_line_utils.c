/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:35:24 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/08 00:35:25 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_realloc(char *line, size_t size)
{
	char	*new_line;
	int		i;

	new_line = (char *)malloc((size_t)(sizeof(char) * size));
	if (!new_line)
		return (NULL);
	i = 0;
	if (!line)
		return (new_line);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

size_t	ft_strlen(const char *line, char specifier)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] && line[i] != specifier)
		i++;
	if (specifier && line[i] == specifier)
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	srclen;
	unsigned int	count;

	srclen = ft_strlen(src, '\0');
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
