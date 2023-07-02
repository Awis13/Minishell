/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:47:24 by Nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 15:27:55 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	lon;

	lon = n;
	if (lon < 0)
	{
		ft_putchar_fd('-', fd);
		lon = lon * -1;
	}
	if (lon >= 10)
		ft_putnbr_fd(lon / 10, fd);
	ft_putchar_fd((lon % 10) + '0', fd);
}
