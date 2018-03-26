#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

/* A program that looks through the input lines, searches 
for the longest and returns its length  */

int gotline(char line[], int maxline); 
void copy(char to[], char from[]);

//print the longest line main function
int main(void)
{	
	int len = 0; //current line length
	int max = 0; //max length seen so far
	char line[MAXLINE]; //input line
	char longestln[MAXLINE]; //longest saved line
	
	printf("Waiting for input...\n");
	
	while((len = gotline(line, MAXLINE)) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(longestln, line);
		}
	}
	if(max > 0)
	{
		printf("\nLongest line:\n%s",longestln);
	}
	
	return 0;
}

//function to read line and return it's length
int gotline(char s[], int limit)
{
	int c, i;
	
	for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

//copy function
void copy(char to[], char from[])
{
	int i = 0;
	
	while((to[i] = from[i]) != '\0')
	{
		i++;
	}
}