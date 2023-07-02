/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:20:58 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/23 13:27:09 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*t;

	len = ft_strlen(s);
	t = malloc(len + 1);
	if (!t)
		return (NULL);
	ft_memcpy(t, s, len);
	t[len] = '\0';
	return (t);
}
