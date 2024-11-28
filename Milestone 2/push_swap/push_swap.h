/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:59 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:10 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// linked list functions

typedef struct node {
	int x;
	struct node* next;
} node_t;

//Nodes/stack start

void	start_stack(char* str, node_t** root);
void	insert_end(node_t** root, int value);

// stack utils

bool	sort_stack(node_t* root);
int		len_stack(node_t* root);
void	sort_three(node_t** root);


// commands

void	sa(node_t** root);
void	sb(node_t** root);
void	ra(node_t** root);
void	rb(node_t** root);
void	rra(node_t** root);
void	rrb(node_t** root);

// Handle errors/frees

void	free_stack(node_t **root);
// int 	duplicates(node_t** root, int value);

// libft

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str, int *i);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int m);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_process(const char *format, va_list args);
int		ft_printf(const char *format, ...);
int		ft_putchr(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long nb);
int		ft_hexa(unsigned int n, int uppercase);
int		ft_pointer(uintptr_t ptr);
int		ft_hexaptr(unsigned long int ptr, char *symbol);
int		ft_putnbr_u(unsigned int nb);

#endif