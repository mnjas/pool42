#include <stdio.h>

int	**init_tab(char *argv, int size);
int	ft_backtracking(int	**tab, int size);

int	main(int argc, char **argv)
{
	int	**tab;
	int	size;

	if (argc != 2)
		return (0);
	printf("%s\n\n", argv[1]);
	size = 6;
	tab = init_tab(argv[1], size);
	ft_backtracking(tab, size);
}
