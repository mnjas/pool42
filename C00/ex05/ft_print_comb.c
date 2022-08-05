#include <unistd.h>

void	ft_print_comb(void)
{
	char	i[3];

	i[0] = '0';
	while (i[0] <= '9')
	{
		i[1] = i[0] + 1;
		while (i[1] <= '9')
		{
			i[2] = i[1] + 1;
			while (i[2] <= '9')
			{
				write(1, &i, 3);
				if (i[0] != '7')
					write(1, ", ", 2);
				i[2]++;
			}
			i[1]++;
		}
		i[0]++;
	}
}
