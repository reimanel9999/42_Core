/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:43 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/06/06 14:00:49 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	printed_chars;

	printed_chars = 0;
	if (!str)
	{
		str = "(null)";
		return (6);
	}
	else if (!*str)
		return (0);
	while (*str)
	{
		write(1, str, 1);
		str++;
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_putnbr(int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb == -2147483648)
	{
		printed_chars += ft_putchr('-');
		printed_chars += ft_putchr('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		printed_chars += ft_putchr('-');
		nb = -nb;
	}
	else if (nb >= 10)
		ft_putnbr(nb / 10);
	printed_chars += ft_putchr(nb % 10 + '0');
	return (printed_chars);
}

int	ft_putnbr_u(unsigned int nb)
{
	int		printed_chars;
	int		m;
	char	buf[12];

	printed_chars = 0;
	m = 11;
	buf[m--] = '\0';
	if (nb == 0)
		buf[m--] = '0';
	else
	{
		while (nb < 0)
		{
			buf[m--] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	printed_chars += ft_putstr(&buf[m + 1]);
	return (printed_chars);
}

int	ft_hexa(unsigned int n, int uppercase)
{
	int		printed_chars;
	char	buf[9];
	int		m;
	char	*hex_digits;

	printed_chars = 0;
	m = 8;
	if (uppercase == 0)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	buf[m--] = '\0';
	if (n == 0)
		buf[m--] = '0';
	else 
	{
		while (n > 0)
		{
			buf[m--] = hex_digits[n % 16];
			n /= 16;
		}
	}
	printed_chars += ft_putstr(&buf[m + 1]);
	return (printed_chars);
}

int	ft_pointer(void *ptr)
{
	int			printed_chars;
	uintptr_t	address;

	printed_chars = 0;
	address = (uintptr_t)ptr;
	printed_chars += ft_putstr("0x");
	printed_chars += ft_hexa((unsigned int)address, 0);
	return (printed_chars);
}
