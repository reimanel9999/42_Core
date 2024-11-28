/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:43 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/20 16:03:12 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb < 0)
	{
		printed_chars += ft_putchr('-');
		printed_chars += ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		printed_chars += ft_putnbr(nb / 10);
		printed_chars += ft_putchr(nb % 10 + '0');
	}
	else if (nb < 10) 
		printed_chars += ft_putchr(nb % 10 + '0');
	return (printed_chars);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb >= 10)
	{
		printed_chars += ft_putnbr(nb / 10);
		printed_chars += ft_putchr(nb % 10 + '0');
	}
	else if (nb < 10) 
		printed_chars += ft_putchr(nb % 10 + '0');
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

int	ft_pointer(uintptr_t ptr)
{
	int			printed_chars;
	uintptr_t	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	printed_chars = 0;
	address = ptr;
	printed_chars += ft_putstr("0x");
	printed_chars += ft_hexaptr(address, "0123456789abcdef");
	return (printed_chars);
}

int	ft_hexaptr(unsigned long int ptr, char *symbol)
{
	int		printed_chars;

	printed_chars = 0;
	if (ptr >= 16)
	{
		printed_chars += ft_hexaptr(ptr / 16, symbol);
		printed_chars += ft_putchr(symbol[ptr % 16]);
	}
	else
		printed_chars += ft_putchr(symbol[ptr]);
	return (printed_chars);
}
