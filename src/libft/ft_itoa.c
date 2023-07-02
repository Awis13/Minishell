/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:44:09 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:28:04 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	lon;
	int		int_len;
	char	*c;

	lon = n;
	int_len = ft_int_count(n);
	if (lon < 0)
	{
		lon = -lon;
		int_len++;
	}
	c = (char *)malloc(sizeof(char) * int_len + 1);
	if (!c)
		return (NULL);
	c[int_len] = '\0';
	c[0] = '-';
	if (n == 0)
		c[0] = '0';
	while (lon != 0)
	{
		c[int_len - 1] = (lon % 10) + '0';
		lon = lon / 10;
		int_len--;
	}
	return (c);
}
