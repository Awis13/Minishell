/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:15:54 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:28:06 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*destc;
	int		i;

	if (!dest && !src)
		return (0);
	srcc = (char *)src;
	destc = (char *)dest;
	i = 0;
	while (n > 0)
	{
		destc[i] = srcc[i];
		n--;
		i++;
	}
	return (dest);
}
