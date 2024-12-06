/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:49:19 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/06 10:30:36 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 601
#define NUM_COUNT 500

int main() {
    int numbers[MAX_NUM] = {0};  // To track numbers that have already been generated
    int uniqueNumbers[NUM_COUNT];
    int count = 0;

    // Seed the random number generator
    srand(time(NULL));

    while (count < NUM_COUNT) {
        int randomNum = rand() % MAX_NUM; // Generate a number between 0 and 200
        
        // Check if the number is unique
        if (numbers[randomNum] == 0) {
            uniqueNumbers[count] = randomNum;  // Store the unique number
            numbers[randomNum] = 1;            // Mark it as generated
            count++;
        }
    }

    // Output the unique random numbers
    printf("500 unique random numbers between 0 and 600:\n");
    for (int i = 0; i < NUM_COUNT; i++) {
        printf("%d ", uniqueNumbers[i]);
    }
    printf("\n");

    return 0;
}

