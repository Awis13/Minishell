/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:34:55 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:28:24 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;
	int	safe;

	i = 0;
	if (ch > 256)
		safe = ch - 256;
	else
		safe = ch;
	while (str)
	{
		if (str[i] == safe)
			return ((char *)str + i);
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return ((char *) str);
}
