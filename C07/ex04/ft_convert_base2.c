#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_result(char *nbr, char *base)
{
	int	i;
	int	j;
	int	result;
	int	base_size;

	result = 0;
	base_size = ft_strlen(base);
	i = 0;
	while (nbr[i] && ft_is_in_base(nbr[i]))
	{
		j = -1;
		while (base[++j])
		{
			if (nbr[i] == base[j])
			{
				result *= base_size;
				result += j;
			}
		}
		i++;
	}
	return (result);
}

int	ft_calculate_char(int nb, int base_size)
{
	int		size;

	size = 1;
	if (nb == 0)
		size += 1;
	else if (nb < 0)
	{
		nb *= -1;
		size += 1;
	}
	while (nb > 0)
	{
		nb /= base_size;
		size += 1;
	}
	return (size);
}

char	*ft_dec_to_base(int nb, char *base)
{
	char	*out;
	int		base_size;
	int		tab_size;
	int		nbr;

	base_size = ft_strlen(base);
	tab_size = ft_calculate_char(nb, base_size);
	out = malloc(tab_size * sizeof(char));
	if (!out)
		return (NULL);
	tab_size -= 1;
	out[tab_size] = '\0';
	nbr = nb;
	if (nbr < 0)
		nbr *= -1;
	while (--tab_size >= 0)
	{
		out[tab_size] = base[nbr % base_size];
		nbr /= base_size;
	}
	if (nb < 0)
		out[0] = '-';
	return (out);
}
