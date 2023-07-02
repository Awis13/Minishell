/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:36:11 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:29:19 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int			i;
	char		*strt;
	int			safe;

	if (ch > 256)
		safe = ch - 256;
	else
		safe = ch;
	strt = (char *)str;
	i = ft_strlen(strt);
	while (i >= 0)
	{
		if (strt[i] == safe)
			return ((char *)strt + i);
		i--;
	}
	return (0);
}
