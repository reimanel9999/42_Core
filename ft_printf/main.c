/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:35:01 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/06/03 14:36:09 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("Decimal: %d\n", 15373);
	ft_printf("Integer: %i\n", 15373);
	ft_printf("Unsigned: %u\n", 789);
	ft_printf("Hex (lower): %x\n", 0123);
    ft_printf("Hex (upper): %X %%\n", 500);
    ft_printf("Nickname: %c, Name: %s\n", 'A', "Emma");
    return 0;
}

