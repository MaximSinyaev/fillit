/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:04:30 by aolen             #+#    #+#             */
/*   Updated: 2019/09/18 15:06:58 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define LEN_ERR (-1)
# define SYM_ERR (-2)
# define FIG_ERR (-3)

# define REPLACE_SYM '*'

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_tetriminos
{
	char		**shape;
	char		letter;
	int			width;
	int			height;
}				t_tetriminos;

t_tetriminos	g_tetro_list[26];

void			print_usage(void);
void			tetrimino_collection(char **figure, int iter);
int				check_tetr(char **tab);
unsigned int	ft_root(unsigned int num);
void			solve(int figures, int min_size);
void			ft_delmap(char ***map);
void			print_map(char **map, int size);

#endif
