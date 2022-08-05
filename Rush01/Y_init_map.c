#include <stdlib.h>
#include <unistd.h>

int	**ft_create_tab(int size)
{
	int	**out;
	int	i;
	int j;

	out = (int **)malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		out[i] = (int *)malloc(size * sizeof(int));
		j = 0;
		while (j < size)
		{
			out[i][j] = 0;
			j++;
		}
		i++;
	}
	return (out);
}

int	ft_valide_number(char c, int size)
{
	return (c >= '1' && c <= (size + '0'));
}

void	ft_row(char **str, int **tab, int size, int *index, int row)
{
	*index = 1;
	while (**str && (*index < (size - 1)))
	{
		if (ft_valide_number(**str, size))
		{ 
			tab[row - 1][*index] = (**str - '0');
			*index += 1;
		}
		*str += 1;
	}
}

void	ft_col(char **str, int	**tab, int size, int *index, int col)
{
	*index = 1;
	while (**str && (*index < (size - 1)))
	{
		if (ft_valide_number(**str, size))
		{ 
			tab[*index][col - 1] = (**str - '0');
			*index += 1;
		}
		*str += 1;
	}
}

int	**init_tab(char *argv, int size)
{
	int	index;
	int	**tab_map;

	tab_map = ft_create_tab(size);
	while (*argv)
	{
		ft_row(&argv, tab_map, size, &index, 1);
		ft_row(&argv, tab_map, size, &index, size);
		ft_col(&argv, tab_map, size, &index, 1);
		ft_col(&argv, tab_map, size, &index, size);
	}
	return (tab_map);
}
