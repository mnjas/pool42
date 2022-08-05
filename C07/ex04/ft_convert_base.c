int		ft_skipe_space_and_find_sign(char **str);
int		ft_get_result(char *nbr, char *base);
char	*ft_dec_to_base(int nb, char *base);

int	ft_check_base(char *base)
{
	char	hash[128];
	int		i;

	if (!base)
		return (0);
	i = -1;
	while (++i < 128)
		hash[i] = 0;
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		hash[(int)base[i]] += 1;
		if (hash[(int)base[i]] > 1)
			return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_skipe_space_and_find_sign(char **str)
{
	int	sign;

	while (**str && ((**str >= '\t' && **str <= '\r') || **str == ' '))
		(*str)++;
	sign = 1;
	while (**str && (**str == '-' || **str == '+'))
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value;

	if (!ft_check_base(base_from) || !ft_check_base(base_to) || !nbr)
		return (0);
	value = ft_skipe_space_and_find_sign(&nbr);
	value *= ft_get_result(nbr, base_from);
	return (ft_dec_to_base(value, base_to));
}
