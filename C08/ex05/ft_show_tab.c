#include <unistd.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		ft_putchar(str[index]);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_put_stock_str(struct s_stock_str stk_str)
{
	ft_putstr(stk_str.str);
	ft_putchar('\n');
	ft_putnbr(stk_str.size);
	ft_putchar('\n');
	ft_putstr(stk_str.copy);
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str)
	{
		ft_put_stock_str(par[index]);
		par++;
	}
}
