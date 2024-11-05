/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:42:34 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/06/06 13:42:37 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_process(const char *format, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (*format == 'c')
		printed_chars += ft_putchr(va_arg(args, int));
	else if (*format == 's')
		printed_chars += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		printed_chars += ft_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		printed_chars += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		printed_chars += ft_putnbr_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		printed_chars += ft_hexa(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		printed_chars += ft_hexa(va_arg(args, unsigned int), 1); 
	else if (*format == '%')
		printed_chars += ft_putchr('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	int		m;

	if (!format)
		return (0);
	va_start(args, format);
	m = 0;
	printed = 0;
	while (format[m])
	{
		if (format[m] == '%' && format[m + 1])
		{
			m++;
			printed = ft_process(&format[m], args);
		}
		else if (!format[m + 1])
			break ;
		else
			printed = ft_putchr(format[m]);
		m++;
	}
	va_end(args);
	return (printed);
}
