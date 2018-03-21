#include <stdio.h>
#include <ctype.h>
#define MAXLEN 26 //max length of input word

/*Program to perform histogram of character frequencies in input text 
by using standart text characters. Can be used in cryptography*/

int main()
{	
	//intro block
	printf("\nReady to work");
	printf(" and waiting for input...\n\n");
	
	//define input storing var
	int c;
	
	//define array representing histogram data and alphabet array
	int len_mas[MAXLEN];
	int alphabet[MAXLEN] = {'a','b','c','d','e','f','g','h','i','j','k',
				'l','m','n','o','p','q','r','s','t','u','v',
				'w','x','y','z'};
	
	//init x axis with defaults
	for(int i = 0; i < MAXLEN; i++)
		len_mas[i] = 0;
	
	//get histogram data 
	while((c = getchar()) != EOF)
	{
		for(int i = 0; i < MAXLEN; i++)
		{
			if(tolower(c) == alphabet[i])
			{
				len_mas[i]++;
			}
		}
	}
	
	//calculate y axis height
	int height = 0;
	
	for(int i = 0; i < MAXLEN; i++)
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
		
		for(int j = 0; j < MAXLEN; j++)
		{
			if(len_mas[j] >= i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n"); //space char
	}
	
	printf("      "); //blank char
	
	for(int i = 0; i < MAXLEN; i++)
		printf("--"); //x axis
	
	printf("> word len"); //axis name and direction sign
	
	printf("\n"); //space char
	
	printf("       ");
	for(int i = 0; i < MAXLEN; i++)
		printf("%c ", alphabet[i]); //x numbers (word lengths)
	
	printf("\n\n");
	return 0;
}
