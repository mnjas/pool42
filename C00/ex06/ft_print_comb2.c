#include <unistd.h>

void	ft_print_comb2(void)
{	
	int		index[2];
	char	numbers[5];

	index[1] = 0;
	numbers[2] = 32;
	while (index[1] <= 98)
	{
		index[0] = index[1] + 1;
		while (index[0] <= 99)
		{
			numbers[4] = (index[0] % 10) + 48;
			numbers[3] = (index[0] / 10) + 48;
			numbers[1] = (index[1] % 10) + 48;
			numbers[0] = (index[1] / 10) + 48;
			write(1, &numbers, 5);
			if (index[1] != 98)
				write(1, ", ", 2);
			index[0]++;
		}
		index[1]++;
	}
}
