/* 
 * Author: YuWen
 * Date: 2017/01/16
 * File: insertion_sort.c
 * Algorithm reference is from wiki - https://en.wikipedia.org/wiki/Insertion_sort
 * A. Algorithn description
 * 		function insertionSortR(array A, int n)
 * 			if n>1
 * 		    	insertionSortR(A,n-1)
 * 		        x = A[n]
 * 		        j = n-1
 * 		        while j >= 0 and A[j] > x
 * 		        	A[j+1] = A[j]
 * 		            j = j-1
 * 		        end while
 * 		        A[j+1] = x
 * 		    end if
 * 		end function
 *
 * B. From website - http://spaces.isu.edu.tw/upload/18833/3/web/sorting.htm#_Toc229730282
 * 每次往後拿一筆記錄，依大小插入已排序好的記錄。也就是說，差入一個記錄在一堆已排好序之記錄中。任何未排序前之第一筆資料可視為已排序好之資料。
 * 	【分析】
 * 	1. 時間複製度，最差與平均時間O(n2)
 * 	2. 只需要一個額外(元素)空間。
 * 	3. 為一穩定排序。
 * 	4. 此方法適用於大部份資料已排序或已排序之資料庫新增資料後進行排序。
 *
 * 	【原理】
 * 	1. 將待排序之資料逐一與已排序後之資料比較，再將資料放入適當位置。
 * 	2. 由最大(最小)逐回合比較至最小(最大)。
 *
 * 	【演算法】
 * 	InSort(int A[], int n)  //插入排序法之副程式
 * 	{
 * 	    int i, j, Temp;
 * 	    for (i = 1; i <= n; i++)
 * 	    {
 * 	    	Temp=A[i];
 * 	        j=i-1;
 * 	        while (Temp<A[j])
 * 	        {
 * 	        	A[j+1]=A[j];
 * 	            j--;
 * 	            if(j==-1) break;
 *          }
 *          A[j+1]=Temp;
 *      }
 *  }
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_NUMBER 10

void swap(int *a, int *b)
{
	int tmp;

	tmp=*a;
	*a=*b;
	*b=tmp;
}

void insertion_sort(int nums[])
{
	int i=0, j=0, tmp=0;

	for (i=1; i<MAX_QUEUE_NUMBER; i++)
	{
		tmp=nums[i];
		j=i-1;
		while (j>=0 && nums[j]>tmp)
		{
			nums[j+1]=nums[j];
			j=j-1;
		}
		nums[j+1]=tmp;
		printf("\nsort-%d: ", i);
		for (j=0; j<MAX_QUEUE_NUMBER; j++)
		{
			printf("%2d, ", nums[j]);
		}
	}
}

int main(void)
{
	int origNums[MAX_QUEUE_NUMBER], insNums[MAX_QUEUE_NUMBER];
	unsigned int seed;
	int i=0;

	seed=(unsigned)time(NULL);
	srand(seed);

	/* generated random numbers */
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
	{
		origNums[i]=rand()%100+1;
		insNums[i]=origNums[i];
	}

	insertion_sort(insNums);

	printf("\n---------------------------------------------------\n");
	printf("\nOrigin Numbers: ");
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%3d,", origNums[i]);
	
	printf("\nSelect Numbers: ");
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%3d,", insNums[i]);
	printf("\n");

	return (0);
}



