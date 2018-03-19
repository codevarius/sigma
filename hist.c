#include <stdio.h>
#define MAXLEN 10 //max length of input word

/*Program to perform histogram of input text word's lengths
by using standart text characters. Max length of input word is 10 letters.
Longer words will not be calculated. Punctuation marks are treated like letters.*/

int main()
{	
	int max_len = MAXLEN + 1;
	
	//intro block
	printf("\nReady to work");
	printf(" and waiting for input. Max length of recognizable word is %d...\n\n",MAXLEN);
	
	//define counter nc & input storing var
	int c, nc, nw;
	nc = 0;
	
	//define array representing histogram data
	int len_mas[max_len];
	
	//init x axis with defaults
	for(int i = 0; i < max_len; i++)
		len_mas[i] = 0;
	
	//get histogram data 
	while((c = getchar()) != EOF)
	{
		
		if(c == ' ' || c == '\n')
		{
			len_mas[nc]++;
			nw++;
			nc = 0;
		}
		else
		{
			nc++;
		}
	}
	
	//calculate y axis height
	int height = 0;
	
	for(int i = 0; i < max_len; i++)
	{
		if(height < len_mas[i])
			height = len_mas[i];
	}
	
	//performing histogram
	printf("\nOUTPUT -->\n\n"); //two blank lines before histogram appears
	printf("     n\n"); //y axis name
	printf("     ^\n"); //y axis direction sign
	
	for(int i = height; i >= 0; i--)
	{
		printf("%5d| ",i); //y axis & numbers (input quantity)
		
		for(int j = 0; j < max_len; j++)
		{
			if(len_mas[j] >= i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n"); //space char
	}
	
	printf("      "); //blank char
	
	for(int i = 0; i < max_len; i++)
		printf("--"); //x axis
	
	printf("> word len"); //axis name and direction sign
	
	printf("\n"); //space char
	
	printf("       ");
	for(int i = 0; i < max_len; i++)
		printf("%d ", i); //x numbers (word lengths)
	
	printf("\n\n");
	return 0;
}