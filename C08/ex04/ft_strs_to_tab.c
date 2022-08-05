#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*output;
	int		str_len;
	int		index;

	str_len = ft_strlen(src) + 1;
	output = malloc(str_len * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (src[index])
	{
		output[index] = src[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}

struct s_stock_str	ft_create(char *str)
{
	struct s_stock_str	output;

	output.size = ft_strlen(str);
	output.str = str;
	output.copy = ft_strdup(str);
	return (output);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					index;
	struct s_stock_str	*output;

	output = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!output)
		return (NULL);
	index = -1;
	while (++index < ac)
		output[index] = ft_create(av[index]);
	output[index].str = 0;
	return (output);
}
