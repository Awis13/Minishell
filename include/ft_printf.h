/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:20:06 by nipostni          #+#    #+#             */
/*   Updated: 2023/02/08 16:24:38 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include "../include/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *printed_len);
void	ft_put_hex(unsigned long n, int *printed_len, bool is_capital);
void	ft_putstr(char *format, int *printed_len);
void	ft_putnbr(long n, int *printed_len);
void	ft_handle_string(char *temp, int *printed_len);
void	ft_handle_ptr(void *ptr, int *printed_len);
void	ft_handle_format(const char *format, va_list args, int *printed_len);
#endif
