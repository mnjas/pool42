#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_size;

	index = 0;
	dest_size = ft_strlen(dest);
	while (src[index])
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest);
}

char	*ft_malloc_size(int size, char **str, char *sep)
{
	int		index;
	int		total_size;

	if (size < 0)
		return (NULL);
	else if (size == 0)
		total_size = 1;
	else
	{
		total_size = 1;
		index = -1;
		while (++index < size)
			total_size += ft_strlen(str[index]);
		total_size += (ft_strlen(sep) * (size - 1));
	}
	return ((char *)malloc(total_size * sizeof(char)));
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	int		index;
	char	*output;
	char	*tmp_out;

	if (!str || !sep)
		return (NULL);
	output = ft_malloc_size(size, str, sep);
	if (!output)
		return (NULL);
	output[0] = '\0';
	if (size == 0)
		return (output);
	tmp_out = output;
	index = -1;
	while (++index < size)
	{
		ft_strcat(output, str[index]);
		if (index != (size - 1))
			ft_strcat(output, sep);
	}
	return (tmp_out);
}
