#include "get_next_line.c"


void	*ft_calloc(size_t nememb, size_t size)
{
	void	*block;
	int	i;

	if (!nmemb || !size)
		return (NULL);
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	block = malloc(nmemb * size);
	while (i < nmemb * size)
	{
		(char *)block[i] = '\0';
		i++;
	}
	return (block);
}
