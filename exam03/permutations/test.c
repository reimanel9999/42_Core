/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:43:27 by manelcarval       #+#    #+#             */
/*   Updated: 2025/05/29 12:37:39 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * next_perm - Generates the next lexicographical permutation of a string.
 * @str: The string to permute (modified in-place).
 * @len: The length of the string.
 *
 * Returns 1 if the next permutation was found, 0 if the string is already the highest permutation.
 * This function implements the standard algorithm for generating the next permutation:
 * 1. Find the largest index i such that str[i] < str[i+1].
 * 2. Find the largest index j > i such that str[i] < str[j].
 * 3. Swap str[i] and str[j].
 * 4. Reverse the substring from i+1 to the end.
 * 
 * Tip: Make sure the string is sorted in ascending order before calling this in a loop to get all permutations.
 */

int next_perm(char *str, int len)
{
    int i;
    int j;
    
    i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return (0);
    j = len - 1;
    while (str[i] >= str[j])
        j--;
    swap(&str[i], &str[j]);
    int left;
    int right;
    left = i + 1;
    right = len - 1;
    while (left < right)
        swap(&str[left++], &str[right--]);
    return (1);
	/*  i  = n - 2;

	while (i >= 0 && str[i] >= str[i + 1])
		i--;
	// printf("i: %d\n", i);
	if (i < 0)
		return 0;
	int j = n - 1;
	while (str[j] <= str[i])
		j--;
	swap(&str[i], &str[j]);
	int left = i + 1, right = n - 1;
	while (left < right)
		swap(&str[left++], &str[right--]);
	return 1; */
	
}

/*
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector (array of strings).
 *
 * This function reads a string from the command line arguments, sorts it, and then prints all
 * its lexicographical permutations using the next_perm function.
 * 
 * Tips:
 * - Pass the string as the first argument (argv[1]) when running the program.
 * - The code currently uses argv[0] (the program name) instead of argv[1]; fix this for correct behavior.
 * - The initial sorting ensures permutations start from the lowest lexicographical order.
 */

int main(int argc, char **argv)
{
    char    *str;
    int     m;

    str = argv[1];
    m = strlen(str);
    if (argc != 2)
        return (1);
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (str[i] > str[j])
                swap(&str[i], &str[j]);
        }
    }
    do
        puts(str);
	while (next_perm(str, m));
    return (0);
}