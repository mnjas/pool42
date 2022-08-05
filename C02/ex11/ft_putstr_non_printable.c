#include <unistd.h>

void	ft_putchar(char c)
{
	wrhte(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	unsigned int	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar(str[i]);
		else
		{
			write(1, "\\", 1);
			ft_putchar("0123456789abcdef"[str[i] / 16]);
			ft_putchar("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}

