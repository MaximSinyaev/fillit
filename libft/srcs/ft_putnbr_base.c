/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 21:00:53 by aolen             #+#    #+#             */
/*   Updated: 2019/09/06 22:24:25 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_base(char *str)
{
	int i;
	int j;

	i = 0;
	if (!(str[0]) || !(str[1]))
		return (0);
	while (str[i])
	{
		if ((str[i] < ' ') || (str[i] == 127))
			return (0);
		else if ((str[i] == '+') || (str[i] == '-'))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		*ft_translate(int nbr, int base_num, int *res_ar)
{
	int			i;
	int			temp;
	long int	lnbr;

	i = 0;
	lnbr = 0 + nbr;
	if (nbr < 0)
		lnbr *= -1;
	while (i++ < 32)
		res_ar[i] = 0;
	i = 0;
	while (ft_power(base_num, i) < lnbr)
		i++;
	while (i > -1)
	{
		temp = lnbr / ft_power(base_num, i);
		res_ar[i] = temp;
		lnbr -= temp * ft_power(base_num, i);
		i--;
	}
	return (res_ar);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			str_len;
	int			j;
	int			res_ar[32];

	str_len = 0;
	if (!ft_check_base(base))
		return ;
	if (nbr < 0)
		ft_putchar('-');
	while (base[str_len])
		str_len++;
	ft_translate(nbr, str_len, res_ar);
	j = 32;
	while ((res_ar[j] == 0) && (j > 0))
		j--;
	while (j > -1)
	{
		ft_putchar(base[res_ar[j]]);
		j--;
	}
}
