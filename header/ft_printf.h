/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:22:46 by smoreron          #+#    #+#             */
/*   Updated: 2023/12/14 03:22:46 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "so_long.h"

int	ft_printf(const char *format, ...);
int	ft_putptr(unsigned long long ptr);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putunisignet(unsigned int n);
int	ft_case(char str, va_list args);
int	ft_puthex(unsigned int n, int up);
int	ft_put_print_ptr(unsigned long long num);
int	ft_lennbr(long int n, int flag);

#endif
