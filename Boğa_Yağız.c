#include<stdio.h>
#include<string.h>

struct IPO   // a structure for IPOs informations
{
	char compname[30];
	char stsymbol[10];
	double offering_price;
	int num_of_shares;
	char underwriters[20];
} ipoarr[100];  // an array for saving IPOs.

int main()
{
	int choise,i=0,j,flag=1;
	char search[30];
	
	
	while(1)   
	{
	printf("\n=== IPO Management System ===\n");  // The main control panel for user 
	printf("1. Add a New IPO\n");
	printf("2. Search for an IPO\n");
	printf("3. Exit\n");
	printf("Enter your choise: ");
	scanf("%d",&choise);
	getchar();
	
	// an if else chain for selection 
	
	if(choise == 1)   //this statement is for adding IPO
	{
		printf("Enter IPO details:\n");
		printf("Company Name: ");
		gets(ipoarr[i].compname);
		printf("Stock Symbol: ");
		gets(ipoarr[i].stsymbol);
		printf("Offering Price: ");
		scanf("%lf",&ipoarr[i].offering_price);
		printf("Number of Shares: ");
		scanf("%d",&ipoarr[i].num_of_shares);
		getchar();
		printf("Underwriters: ");
		gets(ipoarr[i].underwriters);	
		i++;
		printf("IPO added successfully!\n");
	}
	else if(choise == 2) // this statement is for searching IPO
	{
		printf("Enter search term (Company Name or Stock Symbol):");
		gets(search);
		
		for(j=0;j<100;j++)
		{

			if(strcmp(ipoarr[j].compname,search) == 0 || strcmp(ipoarr[j].stsymbol,search) == 0)
			{
				printf("\nIPO Found:\n");
				printf("Company Name: %s\n",ipoarr[j].compname);
				printf("Stock Symbol: %s\n",ipoarr[j].stsymbol);
				printf("Offering Price: %.2lf\n",ipoarr[j].offering_price);
				printf("Number of Shares: %d\n",ipoarr[j].num_of_shares);
				printf("Underwriters: %s\n",ipoarr[j].underwriters);
				flag = 0;
			}
		}
		if(flag == 1) // an error message for not founding IPO
		{
			printf("IPO not found.\n");
		}
		
		
	}
	else if(choise == 3) //exit program
	{
		return 0;
	}
	else if(choise<1 || choise >3) // error message for typing invalid numbers
	{
		printf("Invalid choise. Please enter a valid option.\n");
	}
}
	
}
