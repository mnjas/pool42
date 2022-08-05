void	ft_show_debug(int	**tab, int size, int debug);
/*
int	ft_range_is_ok(int **tab, int size, int x, int y)
{
	int	index;
	index = 1;
	while (index < (size -1))
	{
		if (!line[index])
			return (0);
		index++:
	}
	return (1);
}
int	ft_line_is_full(int **tab, int size, int x, int y)
{
	int	index;
	index = 1;
	while (index < (size -1))
	{
		if (!tab[index])
			return (0);
		index++:
	}
	return (1);
}
int	ft_grid_is_full(int **tab, int size)
{
	int	index;
	index = 1;
	while (index < (size - 1))
	{
		if(!ft_grid_is_full(tab[index]))
			return (0);
		index++;
	}
	return (1);
}
*/
void	ft_extremum(int from, int *to, int size)
{
	if (*to)
		return ;
	if (from == 1)
		*to = (size - 2);
	if (from == (size - 2))
		*to = 1;
}

int	ft_fill_obvious(int	**tab, int size)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (x < size - 1)
	{
		ft_extremum(tab[0][x], &tab[1][x], size);
		ft_extremum(tab[size - 1][x], &tab[size - 2][x], size);
		x++;
	}
	while (y < size - 1)
	{
		ft_extremum(tab[y][0], &tab[y][1], size);
		ft_extremum(tab[y][size - 1], &tab[y][size - 1], size);
		y++;
	}
}

int	ft_backtracking(int	**tab, int size)
{
	ft_show_debug(tab, size, 0);

	ft_fill_obvious(tab, size);
	ft_show_debug(tab, size, 0);
}
