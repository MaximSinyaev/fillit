/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:45:05 by aolen             #+#    #+#             */
/*   Updated: 2019/09/09 14:57:04 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	unsigned int	numbers;
	int				sign;

	i = 0;
	sign = 1;
	numbers = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') && (str[i + 1] - '0' < 10)
		&& (str[i + 1] - '0' >= 0))
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+' && ((str[i + 1] - '0' < 10)
			&& (str[i + 1] - '0' >= 0)))
		i++;
	while ((str[i] - '0' < 10) && (str[i] - '0' >= 0))
	{
		numbers = numbers * 10 + (unsigned int)(str[i++] - '0');
	}
	return ((int)(numbers * sign));
}
