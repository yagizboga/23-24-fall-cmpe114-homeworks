#include<stdio.h>

int scan(int,int);
void reset(int,int*,int*,int*);

int min, max;
int main()
{
	double gpa;
	int  cmpe=0, phys=0, hist=0,scangrade;
	int *cptr,*pptr,*hptr;
	cptr = &cmpe;
	int choise;
	while(1){
	gpa = (cmpe + phys + hist)/75.0;
	printf("--------GRADES--------\n1- CMPE114: %d, (%d)\n2- PHYS102: %d, (%d)\n3- HIST201: %d, (%d)\n",cmpe,&cmpe,phys,&phys,hist,&hist);
	printf("----------------------\nYour GPA is %.1lf/4.0\n----------------------\n",gpa);
	printf("1- Edit class grade\n2- Clear grade\n3- Quit\n");
	
	// used do-while with scan function for printing the suitable message after the invalid number error.
	
	do{
		printf("Enter selection:");
		min = 1;
		max = 3;
		choise=scan(1,3);
		
		
	}while(choise <min || choise>max);

	if(choise == 1)
	{
		do{
		printf("Enter a class number to edit(1-3):");
		min = 1;
		max = 3;
		choise=scan(1,3);
		
		
	}while(choise <min || choise>max);
	
	    do{
		printf("Enter the grade for class %d:",choise);
		min = 0;
		max = 100;
		scangrade=scan(0,100);
		
// used cptr pointer to reach hýst201 and phys101's adress.
	}while(scangrade <min || scangrade>max);
		if(choise == 1)
		{
			*cptr = scangrade;
		}
		else if(choise == 2)
		{
		   pptr = cptr -1;
		   *pptr = scangrade;
		}
		else if(choise == 3)
		{
		   	hptr = cptr -2;
		   	*hptr = scangrade;
		}
		printf("Updated the grade for class %d!\n",choise);
		
		
	}
	else if(choise == 2)
	{
		do{
		printf("Enter a class number to clear(1-3):");
		min = 1;
		max = 3;
		choise=scan(1,3);
		
		
	}while(choise <min || choise>max);
	reset(choise,&cmpe,&phys,&hist);
	
	}
	else if(choise ==3)
	{
		printf("Goodbye :)");
		return 0;
	}
	

}
}
// used min-max for arranging the limits of input in every case.
int scan(int min, int max)
{
	int a;
	
	scanf("%d",&a);
	
	if(a <min || a>max)
	{
		printf("Not a valid number!\n");
	}
	
	return a;
}
// sent all classes' pointers to change the suitable pointer easily.
void reset(int a,int* c,int* p, int* h)
{
	if(a==1)
	{
		*c = 0;
		printf("Cleared grade for class 1!\n");
	}
	else if(a==2)
	{
		*p = 0;
		printf("Cleared grade for class 2!\n");
	}
	else if(a==3)
	{
		*h = 0;
		printf("Cleared grade for class 3!\n");
	}
}
