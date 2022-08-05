int	ft_str_is_uppercase(char *str)
{
	while (str[0] != '\0')
	{
		if (!(str[0] >= 'A' && str[0] <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}
