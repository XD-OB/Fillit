/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 03:16:39 by obelouch          #+#    #+#             */
/*   Updated: 2018/11/07 03:16:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

char		**ft_read_block(int fd)
{
	int		ind[3];
	char	buff[BUFF_SIZE];
	char	**block;

	block = (char**)malloc(sizeof(char*) * 5);
	block[4] = 0;
	if (!read(fd, buff, BUFF_SIZE))
		return (NULL);
	ind[0] = 0;
	ind[2] = 0;
	while (ind[0] < 4)
	{
		block[ind[0]] = (char*)malloc(sizeof(char) * 5);
		ind[1] = 0;
		while (ind[1] < 4)
		{
			if (buff[ind[2]] == '\n')
				ind[2]++;
			block[ind[0]][ind[1]++] = buff[ind[2]++];
		}
		block[ind[0]++][ind[1]] = '\0';
	}
	read(fd, buff, 1);
	return (block);
}

void		minos_coord(char **block, t_point **coord, int *count)
{
	int		ind[4];
	int		ref[2];

	ind[2] = 0;
	ind[0] = -1;
	ind[3] = 0;
	while (block[++ind[0]])
	{
		ind[1] = -1;
		while (block[ind[0]][++ind[1]])
		{
			if (block[ind[0]][ind[1]] == '#' && ind[2] == 0)
			{
				ind[2] = 1;
				ref[0] = ind[0];
				ref[1] = ind[1];
			}
			if (block[ind[0]][ind[1]] == '#')
			{
				coord[(*count) - 1][ind[3]].x = ind[1] - ref[1];
				coord[(*count) - 1][ind[3]].y = ind[0] - ref[0];
				coord[(*count) - 1][ind[3]++].index = (*count) - 1;
			}
		}
	}
}

t_point		**ft_coord(int fd, int *rcount)
{
	int		i;
	int		count;
	char	**block;
	t_point	**coord;

	coord = (t_point**)malloc(sizeof(t_point*) * (*rcount + 1));
	i = -1;
	while (++i < (*rcount))
		coord[i] = (t_point*)malloc(sizeof(t_point) * 5);
	count = 0;
	while ((block = ft_read_block(fd)) != NULL)
	{
		count++;
		minos_coord(block, coord, &count);
	}
	coord[count] = NULL;
	return (coord);
}
