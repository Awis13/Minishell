/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/02/08 16:29:06 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned long n, int *printed_len, bool is_capital)
{
	char	*hex;
	char	*hex_capital;

	hex = "0123456789abcdef";
	hex_capital = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_put_hex(n / 16, printed_len, is_capital);
		ft_put_hex(n % 16, printed_len, is_capital);
	}
	else
	{
		if (is_capital)
			ft_putchar(hex_capital[n], printed_len);
		else
			ft_putchar(hex[n], printed_len);
	}
}

void	ft_handle_string(char *temp, int *printed_len)
{
	if (temp == NULL)
		ft_putstr("(null)", printed_len);
	else
		ft_putstr(temp, printed_len);
}

void	ft_handle_ptr(void *ptr, int *printed_len)
{
	if (ptr == 0)
		ft_putstr("(nil)", printed_len);
	else
	{
		ft_putstr("0x", printed_len);
		ft_put_hex((unsigned long)ptr, printed_len, false);
	}
}

void	ft_handle_format(const char *format, va_list args, int *printed_len)
{
	if (*format == 'd')
		ft_putnbr(va_arg(args, int), printed_len);
	else if (*format == 's')
		ft_handle_string(va_arg(args, char *), printed_len);
	else if (*format == 'c')
		ft_putchar(va_arg(args, int), printed_len);
	else if (*format == 'i')
		ft_putnbr(va_arg(args, int), printed_len);
	else if (*format == 'u')
		ft_putnbr(va_arg(args, unsigned int), printed_len);
	else if (*format == 'x')
		ft_put_hex(va_arg(args, unsigned int), printed_len, false);
	else if (*format == 'X')
		ft_put_hex(va_arg(args, unsigned int), printed_len, true);
	else if (*format == 'p')
		ft_handle_ptr(va_arg(args, void *), printed_len);
	else if (*format == '%')
		ft_putchar('%', printed_len);
}

int	ft_printf(const char *format, ...)
{
	int			printed_len;
	va_list		args;

	printed_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_handle_format(format, args, &printed_len);
			format++;
		}
		else
			ft_putchar(*format++, &printed_len);
	}
	va_end(args);
	return (printed_len);
}

// int main(void)
// {
//     char *x = " %s %s ";
// 	char *y = "hello";
//     ft_printf(x, y, y);
//     printf("\n");
//     printf(x, y, y);
// }