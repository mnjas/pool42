#include <unistd.h>

void	ft_print_combn(char start_with, int n)
{
    if (0 < n && n < 10) 
    {
 		write(1, &start_with, 1);
		if (start_with != ((10 - n) + '0'))
			write(1, ", ", 2);
		ft_print_combn(start_with + 1, n - 1);
	}   
}
