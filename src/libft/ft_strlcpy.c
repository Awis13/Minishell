/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:48 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:28:53 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	const size_t	srclen = ft_strlen(src);

	if (srclen + 1 < n)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (n != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = '\0';
	}
	return (srclen);
}
