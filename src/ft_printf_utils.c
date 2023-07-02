/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awis <awis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:16:14 by nipostni          #+#    #+#             */
/*   Updated: 2023/07/02 13:22:02 by awis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *printed_len)
{
	write(1, &c, 1);
	*printed_len += 1;
}

void	ft_putstr(char *format, int *printed_len)
{
	while (*format)
		ft_putchar(*format++, printed_len);
}

void	ft_putnbr(long n, int *printed_len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", printed_len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', printed_len);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, printed_len);
		ft_putnbr(n % 10, printed_len);
	}
	else
		ft_putchar(n + '0', printed_len);
}
