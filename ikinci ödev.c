#include<stdio.h>
double AnalyzeArray(int arr[],double size);
int PerformQuantumAnalytics(int arr[],int size);
int main(){
	// asking the scientist the 7 quantum elements.
	int arr[7];
	printf("Enter 7 quantum elements:\n");
	
	int i,mod;
	for(i=0;i<7;i++)
	{
		scanf("%d",&arr[i]);
	}
	//asking the scientist the index number to be modified 
	printf("Enter the index of the quantium element to be modified:");
	scanf("%d",&mod);
	// modifying yhe index number by using if-else and modulus.
	if(arr[mod]%2 == 0)
	{
		arr[mod]*=2;
	}
	else if (arr[mod]%2 != 0)
	{
		arr[mod]/=2;
	}
	//printing the new quantium.
	printf("Newly generated quantium:");
	int j;
	for(j = 0;j<7;j++)
	{
		printf("%d ",arr[j]);
	}
	//printing the return value of AnalyzeArray function which calculates the acverage value of the modified array.
	printf("\nAverage value of modified elements:%.2lf",AnalyzeArray(arr,7));
	
	int x,y,temp=0;
	//sorting the array using nested loop.
	for(x = 0;x<6;x++)
	{
		for(y=0;y<6;y++)
		{
			if(arr[y]>arr[y+1])
			{
			temp = arr[y];
			arr[y]=arr[y+1];
			arr[y+1]=temp;
		    }
		}
	}
	//printing the elements after sorting.
	printf("\nSorted elements:\n");
	int k;
	for(k = 0;k<7;k++)
	{
		printf("%d ",arr[k]);
	}
	// sending the first element of array to PerformQuantumAnalytics function which determines the first element is prime number or not.
	PerformQuantumAnalytics(arr,7);
}
//function that calculates the average of the array.
double AnalyzeArray(int arr[],double size)
{
	int sum=0,i;
	double avg;
	for(i=0;i<size;i++)
	{
		sum = sum + arr[i];
	}
	avg = (double)sum / size;
	return avg;
	
}
//function that determines the first element is a prime number or not.
int PerformQuantumAnalytics(int arr[],int size)
{
	int i,fl=0;
	for(i=2;i<arr[0];i++)
	{
		
		if(arr[0]%i==0)
		{	
			fl++;	
		}
		
		
	}
	if(fl != 0 || arr[0]== 1 || arr[0]==0)
	{
		printf("\nThe first element in the sorted array is not a prime number");
	}
	else if(fl == 0)
	{
		printf("\nThe first element in the sorted array is a prime number");
	}
	
}
