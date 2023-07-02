/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:32:55 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:29:30 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*buf;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		buf = malloc(sizeof(char));
		if (!buf)
			return (NULL);
		*buf = '\0';
	}
	else
	{
		if ((ft_strlen(s) - start < len))
			len = ft_strlen(s) - start;
		buf = malloc(sizeof(char) * len +1);
		if (!buf)
			return (NULL);
		ft_strlcpy(buf, (char *)(s + start), len + 1);
	}
	return (buf);
}
