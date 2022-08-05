// Prototype:

void	ft_putchar(char c);

void	ft_putline(char end, char fill, int length)
{
	ft_putchar(end);
	while (length > 2)
	{
		ft_putchar(fill);
		length -= 1;
	}
	if (length > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	length;

	if (x <= 0 || y <= 0)
		return ;
	length = y;
	while (length >= 1)
	{
		if (length == y || length == 1)
			ft_putline('o', '-', x);
		else
			ft_putline('|', ' ', x);
		length -= 1;
	}
}
