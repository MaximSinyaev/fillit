/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:21:24 by aolen             #+#    #+#             */
/*   Updated: 2019/09/09 15:27:01 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void	*tmp_ptr;

	tmp_ptr = ft_memalloc(size);
	ft_memcpy(tmp_ptr, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp_ptr, size);
	free(tmp_ptr);
}
