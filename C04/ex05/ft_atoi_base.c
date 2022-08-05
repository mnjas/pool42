int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_find_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (&str[i]);
}

int	ft_checking(char table[2][128], char *base)
{
	int		index;

	index = 0;
	while (index < 128)
	{
		table[0][index] = 0;
		table[1][index] = 0;
		index++;
	}
	table[0][(int) '+'] = 1;
	table[0][(int) '-'] = 1;
	index = 0;
	while (base[index])
	{
		table[0][(int)base[index]] += 1;
		table[1][(int)base[index]] = index;
		if (table[0][(int)base[index]] > 1)
			return (0);
		index++;
	}
	table[0][(int) '+'] = 0;
	table[0][(int) '-'] = 0;
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		result;
	int		size_base;
	char	hash_table[2][128];
	char	*str_tmp;

	size_base = ft_strlen(base);
	if (size_base < 2 || !ft_checking(hash_table, base))
		return (0);
	str_tmp = ft_find_sign(str, &sign);
	result = 0;
	while (*str_tmp && hash_table[0][(int)*str_tmp])
	{
		result *= size_base;
		result += hash_table[1][(int)*str_tmp];
		str_tmp++;
	}
	return (sign * result);
}
