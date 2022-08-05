void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	loop;

	tmp = 0;
	loop = 0;
	while (loop < size / 2)
	{
		tmp = tab[size - loop - 1];
		tab[size - loop - 1] = tab[loop];
		tab[loop] = tmp;
		loop++;
	}
}
