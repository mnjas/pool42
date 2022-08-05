// Prototypes:

void	ft_putchar(char c);

void	ft_print_line(char left, char middle, char right, int size)
{
	ft_putchar(left);
	while (size > 2)
	{
		ft_putchar(middle);
		size--;
	}
	if (size == 2)
	{
		ft_putchar(right);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	ft_print_line('A', 'B', 'A', x);
	while (y > 2)
	{
		ft_print_line('B', ' ', 'B', x);
		y--;
	}
	if (y == 2)
	{
		ft_print_line('C', 'B', 'C', x);
	}
}
