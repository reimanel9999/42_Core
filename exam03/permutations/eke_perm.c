/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:59:45 by manelcarval       #+#    #+#             */
/*   Updated: 2025/05/27 17:52:30 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int next_permutation(char *str, int n)
{
	int i = n - 2;

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
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	char *str = argv[1];
	int n = strlen(str);
	printf("entao: %d\n", n);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
		}
	}
	do
		puts(str);
	while (next_permutation(str, n));
	return 0;
}
