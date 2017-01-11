/*
 * Author: YuWen  
 * Date: 2017/1/10
 * File: bubble_sort.c
 * Algorithm reference is from wiki - https://en.wikipedia.org/wiki/Bubble_sort
 * Algorithm Description: 
 * 	A. Pseudocode implementation
 * 		procedure bubbleSort( A : list of sortable items )
 * 			n = length(A)
 * 			repeat
 * 				swapped = false
 * 				for i = 1 to n-1 inclusive do
 * 					// if this pair is out of order 
 * 					if A[i-1] > A[i] then
 *						//swap them and remember something changed 
 *						swap( A[i-1], A[i] )
 *						swapped = true
 *					end if
 *				end for
 *			until not swapped
 *		end procedure
 *	
 *	B. Optimizing bubble sort
 *		procedure bubbleSort( A : list of sortable items )
 *			n = length(A)
 *			repeat
 *				swapped = false
 *				for i = 1 to n-1 inclusive do
 *					if A[i-1] > A[i] then
 *						swap(A[i-1], A[i])
 *						swapped = true
 *					end if
 *				end for
 *				n = n - 1
 *			until not swapped
 *		end procedure
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_NUMBER	10

void swap(int *a, int *b)
{
	int tmp;

	tmp=*a;
	*a=*b;
	*b=tmp;
}

void bubble_sort(int nums[])
{
	int i=0, j=0, k=0, swapflag;

	swapflag=2;
	i=0;
	while(1)
	{
		swapflag=0;
		printf("\nsort-%d:", i);
		for (j=1; j<MAX_QUEUE_NUMBER; j++)
		{
			if (nums[j-1] > nums[j])
			{
				swap(&nums[j-1], &nums[j]);
				swapflag=2;
			}
			if (swapflag==2)
			{
				swapflag=1;
				printf("\n\t(");
				for (k=0; k<MAX_QUEUE_NUMBER; k++)
				{
					if (k==j || k==(j-1))
						printf("%3d*,", nums[k]);
					else
						printf("%3d,", nums[k]);
				}
				printf(")");
			}		
		}
		i++;
		if (swapflag==0)
			break;
	}
}

void optimal_bubble_sort(int nums[])
{
	int i=0, j=0, k=0, swapflag, n;

	swapflag=2;
	i=0;
	n = MAX_QUEUE_NUMBER;
	while(1)
	{
		swapflag=0;
		printf("\nsort-%d:", i);
		for (j=1; j<n; j++)
		{
			if (nums[j-1] > nums[j])
			{
				swap(&nums[j-1], &nums[j]);
				swapflag=2;
			}
			if (swapflag==2)
			{
				swapflag=1;
				printf("\n\t(");
				for (k=0; k<MAX_QUEUE_NUMBER; k++)
				{
					if (k==j || k==(j-1))
						printf("%3d*,", nums[k]);
					else
						printf("%3d,", nums[k]);
				}
				printf(")");
			}		
		}
		i++;
		n = n - 1;
		if (swapflag==0)
			break;
	}
}


int main(void)
{
	int origNums[MAX_QUEUE_NUMBER], numbers[MAX_QUEUE_NUMBER], optNums[MAX_QUEUE_NUMBER];
	int i=0;
	unsigned int seed;

	seed=(unsigned)time(NULL);
	srand(seed);
	
	/* generated random numbers */
	for(i=0; i<MAX_QUEUE_NUMBER; i++)
	{
		origNums[i]=rand() % 100 + 1;
		numbers[i]=origNums[i];
		optNums[i]=origNums[i];
	}

	printf("\nOrigin Numbers: ");
	for(i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%2d, ", origNums[i]);

	printf("\n\n===================== Bubble Start ====================");
	bubble_sort(numbers);	
	printf("  \n========================= End =========================\n");


	printf("\n\n============== Optimal Bubble Start ===================");
	optimal_bubble_sort(optNums);
	printf("  \n========================= End =========================\n");


	printf("\nFinal Results for bubble: \n\t");
	for(i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%2d, ", numbers[i]);

	printf("\nFinal Results for optimal bubble: \n\t");
	for(i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%2d, ", numbers[i]);

	printf("\n");	
	return (0);
}
