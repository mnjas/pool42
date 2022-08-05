unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!*src)
		return (i);
	while (src[i] < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (i + 1);
}
