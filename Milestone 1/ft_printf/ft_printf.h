/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:22:01 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/06/14 15:22:04 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

int		ft_process(const char *format, va_list args);
int		ft_printf(const char *format, ...);
int		ft_putchr(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int m);
int		ft_hexa(unsigned int n, int uppercase);
int		ft_pointer(void *ptr);
int		ft_putnbr_u(unsigned int nb);

#endif
