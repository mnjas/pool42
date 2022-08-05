int	ft_row(int **tab, int size, int x, int y, int nb)
{
	int	index;

	if (tab[y][x] || nb < 1 || nb > (size - 2))
		return (0);
	index = 1;
	while (index < (size - 2))
	{
		if (tab[y][index] == nb)
			return (0); 
		index++;
	}
	tab[y][x] = nb;	
	return (1);
}

int	ft_col(int **tab, int size, int x, int y, int nb)
{
	int	index;

	if (tab[y][x] || nb < 1 || nb > (size - 2))
		return (0);
	index = 1;
	while (index < (size - 2))
	{
		if (tab[index][y] == nb)
			return (0); 
		index++;
	}
	tab[y][x] = nb;	
	return (1);
}

int	ft_carre_latin(int **tab, int size, int x, int y, int nb)
{
	int	index[2];
	int	limit[2]

	if (tab[y][x] || nb < 1 || nb > (size - 2))
		return (0);
	index[0] = (x > (size - 2) / 2) * ((size - 2) / 2);
	index[1] = (y > (size - 2) / 2) * ((size - 2) / 2);
	limit[0] = (x > (size - 2) / 2) + ((size - 2) / 2);
	limit[1] = (y > (size - 2) / 2) + ((size - 2) / 2);
	while (index[0] < limit[0])
	{
		while (index[1] < limit[1])
		{
			if (tab[index[1]][index[0]] == nb)
				return (0);
			index[1]++;
		}
		index[0]++;
	}
	tab[y][x] = nb;	
	return (1);
}

int ft_tester(int **tab, int size, int x, int y, int nb)
{
	int ok;

	ok = 1;
	ok &= ft_row(tab, size, x, y, nb);
	ok &= ft_col(tab, size, x, y, nb);
	ok &= ft_carre_latin(tab, size, x, y, nb);

	return (ok);
}
