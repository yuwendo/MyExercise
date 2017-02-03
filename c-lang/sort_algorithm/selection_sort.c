/*
 * Author: YuWen
 * Date: 2017/1/11
 * File: selection_sort.c
 * Algorithm reference is from wiki - https://en.wikipedia.org/wiki/Selection_algorithm
 * 									- https://en.wikipedia.org/wiki/Selection_sort
 * Algorithm Description
 * 	A. Pseudocode implementation
 * 		function select(list[1..n], k)
 * 			for i from 1 to k
 * 				minIndex = i
 * 				minValue = list[i]
 * 				for j from i+1 to n
 * 					if list[j] < minValue
 * 						minIndex = j
 * 						minValue = list[j]
 * 						swap list[i] and list[minIndex]
 * 			return list[k]
 *
 * From website - http://spaces.isu.edu.tw/upload/18833/3/web/sorting.htm#_Toc229730281
 * 類似於氣泡排序法。主要差異在於，第n回合比較時，以一額外資料空間儲存目前第n大(小)，若發現資料順序不對，就將資料互換。依次由上往下比，則結果將由最大(最小)逐回合比較至最小(最大)。
 * 【分析】
 * 1. 比較之回合數=資料數(n)-1。
 * 2. 時間複製度：最差與平均時間O(n^2)
 * 3. 需要一個額外(元素)空間。
 * 4. 為一穩定排序。
 * 5. 資料量小時，使用效果佳(優於氣泡)。
 *
 * 【原理】
 * 1. 未排序前之第一筆資料可視為已排序好之資料
 * 2. 每一回合逐一比較相臨資料，依排序之順序交換位置。
 *
 * 【演算法】
 * SelSort(int A[], int n)  //選擇排序法之副程式
 * {
 * 		int i, j, Temp, NP = 0;
 *      for (i = 1; i <= n - 1; i++)
 *      {
 *      	NP = i;
 *          for (j = i + 1; j <= n; j++)
 *              if (A[j] > A[NP])  NP = j;
 *              {//相鄰兩個的資料交換位置
 *              	Temp = A[i];
 *                  A[i] = A[NP];
 *                  A[NP] = Temp;
 *	       		}
 *      }
 * }
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

void selection_sort(int nums[])
{
	int i=0, j=0, k=0, minIndex=0, minValue=0;

	printf("SelSort: \n");
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
	{
		minIndex=i;
		minValue=nums[i];
		for (j=i+1; j<MAX_QUEUE_NUMBER; j++)
		{
			if (nums[j] < minValue)
			{
				minIndex=j;
				minValue=nums[j];
				swap(&nums[i], &nums[minIndex]);
				printf("\tSort-%2d-%2d (", i, j);
				for (k=0; k<MAX_QUEUE_NUMBER; k++)
					printf("%3d,", nums[k]);
				printf(")\n");
			}
		}
	}
}

int main(void)
{
	int origNums[MAX_QUEUE_NUMBER], selNums[MAX_QUEUE_NUMBER];
	int i=0;
	unsigned int seed;

	seed=(unsigned)time(NULL);
	srand(seed);

	/* generated random numbers */
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
	{
		origNums[i]=rand()%100 + 1;
		selNums[i]=origNums[i];
	}

	selection_sort(selNums);
	printf("\n---------------------------------------------------\n");
	printf("\nOrigin Numbers: ");
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%3d,", origNums[i]);

	printf("\nSelect Numbers:");
	for (i=0; i<MAX_QUEUE_NUMBER; i++)
		printf("%3d,", selNums[i]); 
	printf("\n");

	return (0);
}
