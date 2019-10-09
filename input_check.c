/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:54:49 by aolen             #+#    #+#             */
/*   Updated: 2019/09/23 12:54:51 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	g_x;
int	g_y;

static int	check_fig(char **tab, int i, int j)
{
	int	size;

	size = 0;
	size++;
	tab[i][j] = REPLACE_SYM;
	if (j > 0 && tab[i][j - 1] == '#')
	{
		size += check_fig(tab, i, j - 1);
	}
	if (j < 3 && tab[i][j + 1] == '#')
	{
		size += check_fig(tab, i, j + 1);
	}
	if (i > 0 && tab[i - 1][j] == '#')
	{
		size += check_fig(tab, i - 1, j);
	}
	if (i < 3 && tab[i + 1][j] == '#')
	{
		size += check_fig(tab, i + 1, j);
	}
	if (size > 4)
		return (-1);
	return (size);
}

static int	check_line(char *str, int i, int *size)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (str[j] != '.' && str[j] != '#')
			return (SYM_ERR);
		if (str[j] == '#')
		{
			(*size)++;
			if (*size > 4)
				return (FIG_ERR);
			if (*size == 1)
			{
				g_x = i;
				g_y = j;
			}
		}
	}
	return (*size);
}

int			check_tetr(char **tab)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (++i < 4)
	{
		if ((ft_strlen(tab[i])) != 4)
			return (LEN_ERR);
		if ((size = check_line(tab[i], i, &size)) < 0)
			return (size);
	}
	if (size < 4 || (size = check_fig(tab, g_x, g_y)) < 4)
		return (FIG_ERR);
	return (1);
}
