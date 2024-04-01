#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stringarray                // This is the structure that holds the words. 
{
	char str[10];
} strarr[3];

void turnupper(char st[])        // A function to turn the string to uppercase.
{
	int i;
	
	for(i=0;i<strlen(st);i++)
	{
		st[i]= toupper(st[i]);
	}
}

int main()
{
	int flag = 0,choise,wordarr,i,j,plag;
	char guess[10];
	char *ptr;
	printf("Welcome to Comple!\n");
	
	strcpy(strarr[0].str,"HAPPY");      // These are the words that player chooses by typing a number at the begining. 
	strcpy(strarr[1].str,"CRAZY");
	strcpy(strarr[2].str,"HELLO");
	strcpy(strarr[3].str,"PLANE");
	while(1)
	{
	do
	{
		printf("Please select a word (1-4): ");  //Here, the player chooses the word by typing a number.
        scanf("%d",&choise);
        getchar();
        
        if(choise <= 4 && choise >= 1)
        {
        	flag = 1;
		}
		else
		{
			printf("Please select a number between 1 and 4!\n");  //If the player types an invalid number the program asks again.
		}
	}while(flag == 0);
	wordarr = choise -1;
	printf("\nWord has been selected. Good luck!\n");
	
	
	for(i=0;i<3;i++)   // This loop controls the three attempts 
	{
		printf("\n--Attempt #%d/3--\n",i+1);
		printf("Your guess: ");
		gets(guess);
		turnupper(guess);
		printf("Result: ");
		for(j=0;j<5;j++)  // This loop compares the word and guess 
		{
			ptr = strchr(strarr[wordarr].str,guess[j]);
			if(guess[j] == strarr[wordarr].str[j])   // This if else chain prints the suitable character by checking the guesses and the words characters one by one.
			{
				printf("%c",toupper(guess[j]));
			}
			else if(guess[j] != strarr[wordarr].str[j] && ptr != NULL)
			{
				printf("%c",tolower(guess[j]));
			}
			else
			{
				printf("_");
			}
			
		}
		printf("\n\n");
		if(strcmp(guess,strarr[wordarr].str) == 0)  // if the player wins the game before three attempt this if statement breaks the loop.
		{
			break;
		}
	}
	
	if(strcmp(guess,strarr[wordarr].str) == 0)  //Suitable message and the word are written after the game.
	{
		printf("You win!\n");
		printf("THe word was %s",strarr[wordarr].str);
	}
	else
	{
		printf("Out of attempts! You lose!\n");
		printf("The word was: %s",strarr[wordarr].str);
	}
	
	printf("\n\nWould you like to play again? 1- Yes, 0- No\n"); // the program asks the player to play again.
	scanf("%d",&plag);
	if(plag == 0)
	{
		return 0;
	}
}
	

	
}
