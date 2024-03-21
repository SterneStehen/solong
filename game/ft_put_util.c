/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:22:51 by smoreron          #+#    #+#             */
/*   Updated: 2023/12/14 03:22:51 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_print_ptr(unsigned long long num)
{
	int	count;

	count = 0;
	if (num > 15)
	{
		count += ft_put_print_ptr((num / 16));
		count += ft_put_print_ptr((num % 16));
	}
	else
	{
		if (num < 10)
		{
			if ((ft_putchar(num + '0') == -1))
				return (-1);
			count++;
		}
		else
		{
			if ((ft_putchar(num - 10 + 'a') == -1))
				return (-1);
			count++;
		}
	}
	return (count);
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	if (write(1, "0x", 2) == -1)
		return (-1);
	else
		count = 2;
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		count += ft_put_print_ptr(ptr);
	return (count);
}

int	ft_puthex(unsigned int n, int up)
{
	long long int	num;

	num = (long long int)n;
	if (num > 15)
	{
		if ((ft_puthex((num / 16), up) == -1) \
		|| (ft_puthex((num % 16), up) == -1))
			return (-1);
	}
	else
	{
		if (num < 10)
		{
			if (ft_putchar(num + '0') == -1)
				return (-1);
		}
		else if ((up == 0) && (ft_putchar(num - 10 + 'a') == -1))
			return (-1);
		else if ((up == 1) && (ft_putchar(num - 10 + 'A') == -1))
			return (-1);
	}
	return (ft_lennbr(n, 16));
}

int	ft_lennbr(long int n, int flag)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (flag == 10)
	{
		if (n == -2147483648)
			return (11);
		if (n < 0)
		{
			n = n * -1;
			count++;
		}
	}
	while (n > 0)
	{
		n = n / flag;
		count++;
	}
	return (count);
}

int	ft_putunisignet(unsigned int num)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = num;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	if (num > 9)
		if (ft_putunisignet(num / 10) == -1)
			return (-1);
	if (ft_putchar(num % 10 + '0') == -1)
		return (-1);
	return (count);
}
