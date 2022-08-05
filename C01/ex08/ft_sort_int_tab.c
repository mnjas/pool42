void	ft_sort_int_tab(int *tab, int size)
{
	int	counter;
	int	i;
	int 	temp;

	counter = 1;
	temp = 0;
	while (counter != 0)
	{
		counter = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				counter++;
			}
			i++;
		}
	}
}
