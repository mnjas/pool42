int	ft_iterative_factorial(int nb)
{
	int	output;

	if (nb < 0)
		return (0);
	output = 1;
	while (nb > 1)
	{
		output *= nb;
		nb--;
	}
	return (output);
}
