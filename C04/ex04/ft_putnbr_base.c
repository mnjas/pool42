#include <unistd.h>

int	ft_check_base(char *base)
{
	int		index;
	char	hash_table[128];

	index = -1;
	while (index <= 128)
		hash_table[index++] = 0;
	index = 0;
	while (base[index])
	{
		if (base[index] == '+' || base[index] == '-')
			return (1);
		hash_table[(int)base[index]] += 1;
		if (hash_table[(int)base[index]] > 1)
			return (1);
		index++;
	}
	if (index < 2)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			sizeof_base;
	long long	nb;

	sizeof_base = 0;
	if (ft_check_base(base))
		return ;
	while (base[sizeof_base])
		sizeof_base++;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb < sizeof_base)
		write(1, &base[nb], 1);
	else
	{
		ft_putnbr_base(nb / sizeof_base, base);
		ft_putnbr_base(nb % sizeof_base, base);
	}	
}
