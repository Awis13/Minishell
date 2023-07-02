/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:00:52 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:28:03 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sp1 = s1;
	const unsigned char	*sp2 = s2;

	if (n != 0)
	{
		while (n != 0)
		{
			if (*sp1++ != *sp2++)
				return (*--sp1 - *--sp2);
			n--;
		}
	}
	return (0);
}
