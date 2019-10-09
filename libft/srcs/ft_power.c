/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:13:57 by aolen             #+#    #+#             */
/*   Updated: 2019/09/06 20:16:00 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_power(int nb, int exp)
{
	long int lnbr;

	lnbr = 0 + nb;
	if (exp < 0)
		return (0);
	else if (exp == 0)
		return (1);
	else if (exp == 1)
		return (lnbr);
	else if (exp % 2 == 0)
		return (ft_power(lnbr, exp / 2) * ft_power(lnbr, exp / 2));
	else
		return (ft_power(lnbr, exp - 1) * lnbr);
}
