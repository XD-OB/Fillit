/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 01:40:29 by obelouch          #+#    #+#             */
/*   Updated: 2018/11/07 03:13:11 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H
# define BUFF_SIZE 20
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			index;
}				t_point;

int				is_safe(char **grid, t_point *tetrisa, int a, int b);
void			remove_minos(char **grid, t_point *tetrisa);
void			place_minos(char **grid, t_point *tetrisa, int i, int j);
char			**create_grid(int dim);
int				ft_validate_tetris(char **tet, int *pound);
char			**ft_read_tetriminos(char *buff);
int				ft_check(int fd, int *count_b);
char			**ft_read_block(int fd);
int				count_blocks(int fd);
t_point			**ft_coord(int fd, int *rcount);
int				ft_max_min(int fd, int *rcount);
int				ft_read(int fd);
void			error(char *av, int *rcount);
void			print_grid(char	**grid);
int				recursion(t_point **coord, char **grid, int i, int j);
int				sqrt_sup(int n);
void			ft_putstr(char *s);
void			free_grid(char **grid, int dim);
void			ft_putchar(char c);
void			fillit_solve(t_point **coord, char **grid, int dim);

#endif
