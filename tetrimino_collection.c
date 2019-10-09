/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_collection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:43:31 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/20 20:43:35 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "fillit.h"

static void		malloc_line(char **figure, int iter)
{
	int			s;
	int			ms;

	ms = 0;
	s = -1;
	while (s++ < 4)
	{
		if (figure[s][0] == '.' && figure[s][1] == '.'
		&& figure[s][2] == '.' && figure[s][3] == '.')
		{
			figure[s][0] = '\0';
			ms++;
		}
	}
	g_tetro_list[iter].shape = (char **)malloc(sizeof(char *) * (5 - ms + 1));
	g_tetro_list[iter].shape[5 - ms - 1] = NULL;
}

static void		malloc_words(char **figure, int iter)
{
	int			s;
	int			f;
	int			len;
	int			i;

	s = -1;
	f = 0;
	while (s++ < 4)
	{
		len = 0;
		i = -1;
		while (i++ < 5)
		{
			if (figure[s][i] == '\0')
				break ;
			if (figure[s][i] != 'x')
				len++;
		}
		if (len != 0)
		{
			g_tetro_list[iter].shape[f] = (char*)malloc(sizeof(char) * (len));
			f++;
		}
	}
}

static void		height_width_and_free(int f, int j, int iter, char **figure)
{
	int i;

	i = 0;
	g_tetro_list[iter].height = f;
	g_tetro_list[iter].width = j;
	while (i < 4)
	{
		free(figure[i]);
		i++;
	}
}

static void		write_shape(char **figure, int iter)
{
	int			s;
	int			i;
	int			f;
	int			j;

	s = -1;
	f = 0;
	while (s++ < 4)
	{
		i = -1;
		if (figure[s][0] == '\0')
			continue ;
		j = 0;
		while (i++ < 5)
		{
			if (figure[s][i] != 'x' && figure[s][i] != '\0')
			{
				g_tetro_list[iter].shape[f][j] = figure[s][i];
				j++;
			}
		}
		g_tetro_list[iter].shape[f][j] = '\0';
		f++;
	}
	height_width_and_free(f, j, iter, figure);
}

void			tetrimino_collection(char **figure, int iter)
{
	int			s;
	int			i;

	i = -1;
	malloc_line(figure, iter);
	while (i++ < 4)
	{
		s = -1;
		if ((figure[0][i] == '.' || figure[0][i] == '\0')
		&& (figure[1][i] == '.' || figure[1][i] == '\0')
			&& (figure[2][i] == '.' || figure[2][i] == '\0')
			&& (figure[3][i] == '.' || figure[3][i] == '\0'))
			while (s++ < 4)
				if (figure[s][i] != '\0')
					figure[s][i] = 'x';
	}
	malloc_words(figure, iter);
	write_shape(figure, iter);
	g_tetro_list[iter].letter = 'A' + iter;
}
