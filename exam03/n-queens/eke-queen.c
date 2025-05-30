/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:35:19 by manelcarval       #+#    #+#             */
/*   Updated: 2025/05/26 19:09:33 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int solcount = 0;

int is_safe(int *sol, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if (sol[i] == col || sol[i] - i == col - row || sol[i] + i == col + row)
			return 0;
	}
	return 1;
}

void solve(int *sol, int n, int row)
{
	if (row == n)
	{
		solcount++;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				printf("%d", sol[i]);
			else
				printf(" %d", sol[i]);
		}
		printf("\n");
		return ;
	}
	for (int col = 0; col < n; col++)
	{
		if(is_safe(sol, row, col))
		{
			sol[row] = col;
			solve(sol, n, row + 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int n = atoi(av[1]);
	int sol[n];
	solve(sol, n, 0);
	if (solcount == 0)
		return 1;
	return 0;
}
