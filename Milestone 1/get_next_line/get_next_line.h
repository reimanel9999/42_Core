/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:04:53 by manelcarval       #+#    #+#             */
/*   Updated: 2025/06/16 11:26:19 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLINE_H
# define MYLINE_H

#  define BUFFER_SIZE 1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t num);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t n);

#endif