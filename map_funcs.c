/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:49:44 by aolen             #+#    #+#             */
/*   Updated: 2019/09/24 12:49:49 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_delmap(char ***map)
{
	int i;

	i = -1;
	while ((*map)[++i])
		ft_strdel(&((*map)[i]));
	free(*map);
	*map = NULL;
}

void	print_map(char **map, int size)
{
	int i;

	i = -1;
	while (map[++i])
	{
		write(1, map[i], size);
		ft_putchar('\n');
	}
}
