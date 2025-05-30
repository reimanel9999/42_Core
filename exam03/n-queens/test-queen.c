/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_queen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:01:32 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/05/29 20:12:44 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * allowed - Checks if a queen can be safely placed in a given column.
 * @positions: Array storing the column positions of previously placed queens.
 * @queen_nr:  The current queen's row index.
 * @pos:       The column to check for the current queen.
 *
 * Returns 1 if it's safe to place a queen at (queen_nr, pos), 0 otherwise.
 * It checks column and diagonal conflicts with all previously placed queens.
 *
 * Tip: To replicate, use an array where positions[i] gives the column of the queen in row i.
 */
static int  allowed(int positions[1000], int queen_nr, int pos)
{
    int i;
    i = 0;
    while (i < queen_nr)
    {
        if (positions[i] == pos
    		|| queen_nr - i == pos - positions[i]
            || queen_nr - i == positions[i] - pos)
            return (0);
        i += 1;
    }
    return (1);
}

/*
 * print_solution - Outputs a valid arrangement of queens.
 * @positions: Array of queen column positions for each row.
 * @n:         Number of queens (and size of the board).
 *
 * Prints the solution as a sequence of column numbers, separated by spaces.
 *
 * Tip: This function is called when a full solution is found. You can adapt the output format as needed.
 */
static void print_solution(int positions[1000], int n)
{
    int     i;
    char    c;
    i = 0;
    while (i < n)
    {
        c = '0' + positions[i];
        write(1, &c, 1);
		write(1, " ", 1);
        i += 1;
    }
    write(1, "\n", 1);
}

/*
 * recursion - Recursively tries to place queens row by row.
 * @positions: Array tracking queen positions.
 * @n:         Total number of queens/board size.
 * @c:         Current row (queen number) being processed.
 *
 * Tries every column in the current row, and if allowed, places a queen and recurses to the next row.
 * Prints the solution when all queens are placed.
 *
 * Tip: This is a classic backtracking approach. To replicate, call with c=0 and an empty positions array.
 */
static void recursion(int positions[1000], int n, int c)
{
    int pos;
    pos = 0;
    while (pos < n)
    {
        if (allowed(positions, c, pos))
        {
            positions[c] = pos;
            if (c == n - 1)
                print_solution(positions, n);
            else
                recursion(positions, n, c + 1);
        }
        pos++;
    }
}

/*
 * main - Entry point. Reads board size and starts the N-Queens solver.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Expects the board size (number of queens) as a command-line argument.
 * Initializes the positions array and starts the recursive search.
 *
 * Tip: Run the program with the desired board size, e.g., './a.out 8' for 8-queens.
 */
int main(int argc, char **argv)
{
    int		positions[1000];
	char	*temp;
	int		queen;
	
	if (argc != 2)
		return 1;
	temp = argv[1];
	queen = atoi(temp);
    recursion(positions, queen, 0);
}