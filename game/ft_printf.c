/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:22:40 by smoreron          #+#    #+#             */
/*   Updated: 2023/12/14 03:22:40 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count ;

	count = 0;
	if (s == NULL)
	{
		if ((write (1, "(null)", 6)) == -1)
		{
			return (-1);
		}
		return (6);
	}
	else
	{
		while (*s)
		{
			if ((ft_putchar(*s)) == -1)
				return (-1);
			count ++;
			s++;
		}
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long long int	num;

	num = n;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num *= -1;
	}
	if (num > 9)
	{
		if ((ft_putnbr(num / 10)) == -1)
			return (-1);
		if ((ft_putnbr(num % 10)) == -1)
			return (-1);
	}
	else
	{
		if ((ft_putchar(num + '0')) == -1)
			return (-1);
	}
	return (ft_lennbr(n, 10));
}

int	ft_case(char str, va_list args)
{
	if (str == 'c')
		return (ft_putchar (va_arg (args, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_putptr(va_arg(args, unsigned long long int)));
	else if (str == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str == 'u' )
		return (ft_putunisignet(va_arg(args, unsigned int)));
	else if (str == 'X')
		return (ft_puthex(va_arg(args, unsigned long long int), 1));
	else if (str == 'x')
		return (ft_puthex(va_arg(args, unsigned long long int), 0));
	else if (str == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_case(format[i++], ap);
		}
		else
		{
			count += ft_putchar(format[i++]);
		}
		if (count == -1)
		{
			return (-1);
		}
	}
	return (count);
}
