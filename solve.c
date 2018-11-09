/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:33:43 by obelouch          #+#    #+#             */
/*   Updated: 2018/11/07 02:04:50 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int			is_safe(char **grid, t_point *tetrisa, int a, int b)
{
	int		index;
	int		dim;

	dim = 0;
	while (grid[0][dim])
		dim++;
	index = 1;
	if (grid[a][b] != '.')
		return (0);
	while (index < 4)
	{
		if ((tetrisa[index].x + b) >= 0 && (tetrisa[index].x + b) < dim
				&& (tetrisa[index].y + a) < dim)
		{
			if (grid[tetrisa[index].y + a][tetrisa[index].x + b] != '.')
				return (0);
		}
		else
			return (0);
		index++;
	}
	return (1);
}

void		place_minos(char **grid, t_point *tetrisa, int i, int j)
{
	int		ind;

	ind = 0;
	while (ind < 4)
	{
		grid[tetrisa[ind].y + i][tetrisa[ind].x + j] = (tetrisa[0].index + 65);
		ind++;
	}
	tetrisa[4].x = j;
	tetrisa[4].y = i;
}

int			recursion(t_point **tetrisa, char **grid, int i, int j)
{
	if (!*tetrisa)
		return (1);
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (is_safe(grid, *tetrisa, i, j) == 1)
			{
				place_minos(grid, *tetrisa, i, j);
				if (recursion(tetrisa + 1, grid, 0, 0) == 1)
					return (1);
				else
					remove_minos(grid, *tetrisa);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void		fillit_solve(t_point **coord, char **grid, int dim)
{
	int		l;

	l = 0;
	while (!(recursion(coord, grid, 0, 0)))
	{
		free_grid(grid, dim);
		l++;
		grid = create_grid(dim + l);
	}
	print_grid(grid);
}
