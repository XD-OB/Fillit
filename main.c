/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 03:17:06 by obelouch          #+#    #+#             */
/*   Updated: 2018/11/07 03:27:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void		error(char *av, int *rcount)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1 || !ft_max_min(fd, rcount))
	{
		ft_putstr("error\n");
		exit(-1);
	}
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1 || !ft_read(fd))
	{
		ft_putstr("error\n");
		exit(-1);
	}
	close(fd);
}

int			main(int ac, char **av)
{
	int		fd;
	int		num_block;
	char	**grid;
	t_point	**coord;

	num_block = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit <source_file>\n");
		return (1);
	}
	error(av[1], &num_block);
	fd = open(av[1], O_RDONLY);
	coord = ft_coord(fd, &num_block);
	close(fd);
	fd = open(av[1], O_RDONLY);
	grid = create_grid(sqrt_sup(num_block * 4));
	fillit_solve(coord, grid, sqrt_sup(num_block * 4));
	return (0);
}
