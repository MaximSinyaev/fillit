/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:35 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/13 12:35:37 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

unsigned int			ft_root(unsigned int figs_num)
{
	unsigned int root;
	unsigned int i;

	root = figs_num * 4;
	if (root + 1 < root)
		return (0);
	i = 2;
	while (i <= root)
	{
		if (i * i >= root)
			return (i);
		i++;
	}
	return (0);
}
