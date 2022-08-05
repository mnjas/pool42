// Protoype

void	ft_putchar(char c);

void	ft_line(char str[3], int x)
{
	ft_putchar(str[0]);
	while (x > 2)
	{
		ft_putchar(str[1]);
		x--;
	}
	if (x > 1)
		ft_putchar(str[2]);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	ft_line("ABC", x);
	while (y > 2)
	{
		ft_line("B B", x);
		y--;
	}
	if (y > 1)
		ft_line("CBA", x);
}
