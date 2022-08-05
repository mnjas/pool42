char	*ft_strcapitalize(char *str)
{
	int	i;
	int	upcase;

	i = 0;
	upcase = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'a' && str[i] <= 'z' ||
			 (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (upcase && str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!upcase && str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			upcase = 0;
		}
		else
			upcase = 1;
		i++;
	}
	return (str);
}
