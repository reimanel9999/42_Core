/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:59 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 21:43:32 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# define HASH_TABLE_SIZE (1000000)

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
	int index;
	struct node* next;
} node_t;

void	process(node_t **stack_a, node_t **stack_b);

// stack utils

int		len_stack(node_t* root);
void	start_stack(char* str, node_t** root, int *error);
void	insert_end(node_t** root, int value);
void	assign_indices(node_t **root);
bool	sort_stack(node_t* root);
void	indices(node_t **root, int *arr, int len);
int		max(node_t *stack);
int		min(node_t *stack);

// sort_small

void	sort_two(node_t **root);
void	sort_three(node_t** root);
void	sort_five(node_t **stack_a, node_t **stack_b);
void	small_sort_b(node_t **stack_a, node_t **stack_b);
int		find_nextbig_index_position(node_t *stack_a, int index);
int		find_sm_idx(node_t *a);
int		find_sm2_idx(node_t *stack);
int		find_index_position(node_t *a, int index);

// sort_big

void	sort_big(node_t **stack_a, node_t **stack_b);
void	sorted_to_stack_a(node_t **stack_a, node_t **stack_b);
void	chunk_move(node_t **stack_a, node_t **stack_b, int start, int end);

int		calculate_rotations(node_t *stack, int target_index);
void	rotate_position(node_t **stack, int target_index);

// sort_utils

int		calculate_chunk_size(int total);
int		in_range(node_t *stack, int start, int end);
int		find_closest_index_position(node_t *stack, int start, int end);
int		find_position(node_t *stack, int target_index);
int		calculate_distance(int position, int len);
int		find_closest_position(node_t *stack, int start, int end, int len);

void	move_min_or_max_to_top(node_t **stack_b);
void	put_in_position(node_t **stack_a, node_t **stack_b);
int		closest_above(node_t *stack, int target_index);

// Finding indexes

int		find_from_bottom(node_t *stack, int start, int end);
int		find_from_top(node_t *stack, int start, int end);
int		find_top_target(node_t *stack, int target);
int		find_bottom_target(node_t *stack, int target);

// Handle errors/frees

void	free_stack(node_t **root);
int		check_duplicates(node_t *root);
int		error_handler(int m);

// ft_qsort

typedef struct s_qsort
{
    void    *base;
    size_t  size;
    int     (*compar)(const void *, const void *);
}   t_qsort;

void	ft_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
void	quicksort(t_qsort *data, size_t low, size_t high);
int		compare(const void *a, const void *b);
size_t	partition(t_qsort *data, size_t low, size_t high);
void	ft_swap(void *a, void *b, size_t size);
// rotates

void	rotate_target(node_t **stack_a, int target_index);
void	rotate_a(node_t **stack_a, int start, int end);
int		cal_pos(int top_position, int bottom_position, int stack_len);
void	perform_rotation(node_t **stack_a, int optimal_position, int stack_len, int top_position);



// commands

void	sa(node_t** root);
void	sb(node_t** root);
void	pa(node_t **root_a, node_t **root_b);
void	pb(node_t **root_a, node_t **root_b);
void	ra(node_t** root);
void	rb(node_t** root);
void	rra(node_t** root);
void	rrb(node_t** root);


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
int		ft_atoi(const char *str, int *i, int *error);
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