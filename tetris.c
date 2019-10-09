/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:17:39 by aolen             #+#    #+#             */
/*   Updated: 2019/09/23 20:17:40 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int g_size;
int g_figures;

static void		delete_fig(char **map, char flag)
{
	int i;
	int j;
	int sqr;

	i = g_size;
	sqr = 0;
	while (--i >= 0)
	{
		j = g_size;
		while (--j >= 0)
		{
			if (map[i][j] == flag)
			{
				map[i][j] = '.';
				++sqr;
			}
			if (sqr == 4)
				return ;
		}
	}
}

static int		place_figure(int fig_n, char **map, int line, int col)
{
	int i;
	int j;

	if ((line + g_tetro_list[fig_n].height > g_size) ||
		(col + g_tetro_list[fig_n].width > g_size))
		return (0);
	i = -1;
	while (++i < g_tetro_list[fig_n].height)
	{
		j = -1;
		while (++j < g_tetro_list[fig_n].width)
		{
			if (g_tetro_list[fig_n].shape[i][j] != '.')
			{
				if (map[line + i][col + j] == '.')
					map[line + i][col + j] = g_tetro_list[fig_n].letter;
				else
					return (0);
			}
		}
	}
	return (1);
}

static void		backtrack(char **map, int fig)
{
	int i;
	int j;

	if (fig == g_figures)
	{
		print_map(map, g_size);
		ft_delmap(&map);
		exit(0);
	}
	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			if (map[i][j] == '.' || g_tetro_list[fig].shape[0][0] == '.')
				if (place_figure(fig, map, i, j) != 0)
				{
					backtrack(map, fig + 1);
				}
			delete_fig(map, g_tetro_list[fig].letter);
		}
	}
}

void			solve(int figures, int min_size)
{
	char	**map;
	int		i;

	g_size = min_size;
	g_figures = figures;
	map = malloc(sizeof(*map) * (min_size + 1));
	i = -1;
	while (++i < g_size)
	{
		map[i] = malloc(sizeof(**map) * (min_size + 1));
		map[i][min_size] = 0;
		ft_memset(map[i], '.', min_size);
	}
	map[min_size] = NULL;
	backtrack(map, 0);
	ft_delmap(&map);
	if (min_size < 12)
		solve(figures, min_size + 1);
}
