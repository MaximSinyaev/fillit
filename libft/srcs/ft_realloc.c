/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:28:14 by aolen             #+#    #+#             */
/*   Updated: 2019/09/09 15:48:00 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, size_t new_size)
{
	char	*new_ptr;
	size_t	cur_size;

	if (!ptr)
		return (NULL);
	cur_size = ft_strlen(ptr);
	if (cur_size > new_size)
		return (ptr);
	new_ptr = ft_strnew(new_size);
	ft_memcpy((void *)new_ptr, (void *)ptr, new_size);
	free(ptr);
	return (new_ptr);
}
