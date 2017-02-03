/*
 * Author:	YuWen
 * Date:	02/03/2017
 * File:	guess_numbers.c
 * Descriptions:
 * 		1. guess numbers
 * 		2. XAXB
 */

/***************************** Includes **************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************************** Definitions *************************/
#define MENU_SIZE	(sizeof(guess_menu)/sizeof(guess_menu[0]))
/* Functions */
#define GUESS_NUMBERS_1_TO_1000	1
#define GUESS_XAXB_NUMBERS		2
#define GUESS_EXIT				3

const char *guess_menu[]={
/* 0 */"\nGuess numbers selections:\n",
/* 1 */"1. Guess a numbers(1 ~ 1000)\n",
/* 2 */"2. The ?A?B games for 4 numbers\n",
/* 3 */"3. exit\n"
/*n-1*/"--------------------------------------------\n"
/* n */"Select menu: "
};

/************************ Local variables ************************/

/********************** Function prototypes **********************/
void guess_numbers_1_to_1000(void);
void guess_xaxb_numbers(void);

void guess_numbers_1_to_1000(void)
{
	unsigned int seed;
	int answer, num=0, max=1000, min=1, count=0;

	seed=(unsigned)time(NULL);
	srand(seed);

	/* generated answer */
	answer = rand() % 1000 + 1;
	count=0;
	while (num!=answer)
	{
		printf("\nNumber is between %d and %d\n", min, max);
		printf("Your numbers: ");
		scanf("%d", &num);
		if (num >max || num<min)
		{
			printf("Please input correct numbers!!!!!\n");
			continue;
		}

		if (num>answer)
			max=num;
		else
			min=num;
		count++;
	}
	printf("\n================================================\n");
	printf("!!! WIN !!! Guess %d times\n", count);
}

void guess_xaxb_numbers(void)
{
	unsigned int seed;
	int i=0, j=0, num=0, numA=0, numB=0;
	int pos[4], ans[4];	

	seed=(unsigned)time(NULL);
	srand(seed);

	for(i=0; i<4; i++)
	{
		ans[i]=rand()%10;
		j=i-1;
		while (j>=0)
		{
			if (ans[i]==ans[j]) 
			{
				i--;
				break;
			}
			j--;
		}
	}

	while (numA!=4) 
	{
		printf("\nEnter numbers. Each number is 0 to 9. (Ex: 0128, or 5318)\n");
		printf("Your number (%dA %dB): ", numA, numB);
		scanf("%d", &num);
		if (num>9876 || num<123)
		{
			printf("!!!ERROR: Please enter right number!!!\n");
			continue;
		}
		
		pos[0]=num/1000;
		num=num%1000;
		pos[1]=num/100;
		num=num%100;
		pos[2]=num/10;
		pos[3]=num%10;
		if ((pos[0]==pos[1]) || (pos[2]==pos[3]) || (pos[0]==pos[2]) || (pos[1]==pos[3]))
		{
			printf("!!!ERROR: Please enter right number!!!\n");
			continue;
		}
	
		numA=0;
		numB=0;
		for (i=0; i<4; i++)
		{
			if (pos[i]==ans[i])
				numA++;
			else {
				for (j=0;j<4; j++)
				{
					if (pos[i]==ans[j])
						numB++;
				}
			}
		}

	}	
	printf("\n==============================================================\n");
	printf("!!! WIN !!!\n");
}

int main(void)
{
	int sel_num=0, i=0;

	while (1) 
	{
		for (i=0; i<MENU_SIZE; i++)
			printf(guess_menu[i]);
		scanf("%d", &sel_num);

		switch (sel_num)
		{
			case GUESS_NUMBERS_1_TO_1000:
				guess_numbers_1_to_1000();
				break;
			case GUESS_XAXB_NUMBERS:
				guess_xaxb_numbers();
				break;
			case GUESS_EXIT:
				return (0);
			default:
				printf("ERROR: Not support this function\n");
				break;
		}
	}

	return (0);
}

