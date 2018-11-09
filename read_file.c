/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 01:47:16 by obelouch          #+#    #+#             */
/*   Updated: 2018/11/07 01:50:25 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int			ft_validate_tetris(char **tet, int *pound)
{
	int		ind[3];

	ind[2] = 0;
	ind[0] = 0;
	while (tet[ind[0]])
	{
		ind[1] = 0;
		while (tet[ind[1]])
		{
			if (tet[ind[0]][ind[1]] == '#' && ++(*pound))
			{
				if (ind[0] < 3 && tet[ind[0] + 1][ind[1]] == '#')
					ind[2] += 1;
				if (ind[0] > 0 && tet[ind[0] - 1][ind[1]] == '#')
					ind[2] += 1;
				if (ind[1] < 3 && tet[ind[0]][ind[1] + 1] == '#')
					ind[2] += 1;
				if (ind[1] > 0 && tet[ind[0]][ind[1] - 1] == '#')
					ind[2] += 1;
			}
			ind[1]++;
		}
		ind[0]++;
	}
	return (ind[2]);
}

char		**ft_read_tetriminos(char *buff)
{
	int		r;
	int		i[2];
	char	**block;

	block = (char**)malloc(sizeof(char*) * 5);
	block[4] = 0;
	i[0] = -1;
	r = 0;
	while (++i[0] < 4)
	{
		block[i[0]] = (char*)malloc(sizeof(char) * 5);
		i[1] = -1;
		while (++i[1] < 4)
		{
			if (buff[r] == '\n')
				r++;
			block[i[0]][i[1]] = buff[r++];
		}
		block[i[0]][i[1]] = '\0';
	}
	return (block);
}

int			ft_read(int fd)
{
	char	buff[BUFF_SIZE];
	int		count;
	int		pound;

	count = 0;
	while (read(fd, buff, BUFF_SIZE) >= 0)
	{
		pound = 0;
		count = ft_validate_tetris(ft_read_tetriminos(buff), &pound);
		if (pound > 4)
			return (0);
		if (count != 6 && count != 8)
			return (0);
		if (read(fd, buff, 1) == 0)
			break ;
	}
	return (1);
}
