/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:44:31 by obelouch          #+#    #+#             */
/*   Updated: 2018/11/07 03:10:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int			ft_check(int fd, int *count_b)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;

	while ((ret = read(fd, buff, BUFF_SIZE)) >= 1)
	{
		i = 0;
		buff[ret] = '\0';
		while (i < 20)
		{
			if ((i == 4 || i == 9 || i == 14 || i == 19)
					&& buff[i] != '\n')
				return (0);
			if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
				return (0);
			i++;
		}
		(*count_b)++;
		ret = read(fd, buff, 1);
		if (ret == 1 && buff[0] != '\n')
			return (0);
	}
	if (buff[0] == '\n')
		return (0);
	return (1);
}

int			ft_max_min(int fd, int *rcount)
{
	int		res;
	int		count;

	count = 0;
	res = ft_check(fd, &count);
	if (count < 1 || count > 26)
		return (0);
	(*rcount) = count;
	return (res);
}
