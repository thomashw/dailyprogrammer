/*
Created by: Thomas Hewton-Waters
reddit.com/r/dailyprogrammer

we all know the classic "guessing game" with higher 
or lower prompts. lets do a role reversal; you 
create a program that will guess numbers between 
1-100, and respond appropriately based on whether 
users say that the number is too high or too low. 
Try to make a program that can guess your number 
based on user input and great code!
*/

#include "stdio.h"

static char readChar();

int main()
{
	char c = ' ';
	int min = 1;
	int max = 100;
	int guess = 50;
	int diff;

	printf("Think of a number between 1 and 100.\n");
	printf("Is it %d? (y)es, (h)igher, (l)ower?\n", guess);
	c = readChar();

	while(c != 'y')
	{
		if(c == 'h')
		{
			min = guess;
			diff = ((max - guess) / 2) == 0 ? 1 : (max - guess) / 2;
			guess += diff;
		}
		else if(c == 'l')
		{
			max = guess;
			diff = ((guess - min) / 2) == 0 ? 1 : ((guess - min) / 2);
			guess -= diff;
		}

		if(guess == 1 || guess == 100 || (max - min == 2))
			break;

		if(max - min == 1)
		{
			printf("You aren't answering correctly.\n");
			return 0;
		}

		printf("Is it %d? (y)es, (h)igher, (l)ower?\n", guess);
		c = readChar();		
	}

	printf("I win! Your number is %d.\n", guess);

	return 0;
}

static char readChar()
{
	char c[2];
	fgets(c, sizeof(c), stdin);

	return c[0];
}
