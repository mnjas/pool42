#include <unistd.h>

void	ft_put_line(int	*dat, int x, int width)
{
	while (x < width)
	{
		write(1, "0123456789" + dat[x], 1);
		if (x != width - 1)
			write(1, " ", 1);
		x++;
	}
	write(1, "\n", 1);
}

void	ft_show(int **dat, int x, int y, int width, int height)
{
	while (y < height)
	{
		ft_put_line(dat[y], x, width);
		y++;
	}
}

void	ft_show_debug(int	**tab, int size, int debug)
{
	if (debug == 0)
	{
		ft_show(tab, 0, 0, size, size);
		write(1, "\n", 1);
		ft_show(tab, 1, 1, (size - 1), (size - 1));
	}
	else if (debug > 0)
		ft_show(tab, 0, 0, size, size);
	else
		ft_show(tab, 1, 1, (size - 1), (size - 1));
	write(1, "\n", 1);
}
