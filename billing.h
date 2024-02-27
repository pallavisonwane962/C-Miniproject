#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int size,i;
struct bill{
	int billno,q;
	char cname[90],mediname[90];
	float medi_qty,medi_rate,total;
	char date[90];
};
struct bill b;
//======================================================CASE 1:CREATE DATA=====================================================================================
void bill()
{    
	printf("ENTER BILL INFORMATION\n");
	fptr=fopen("bill-file.txt","a");
	printf("\nenter bill no:");
	scanf("%d",&b.billno);
	printf("\nenter bill date:");
	scanf("%s",&b.date);
	printf("\nenter customer name:");
	scanf("%s",b.cname);
	printf("\nenter medicine name:");
	scanf("%s",&b.mediname);
	printf("\nenter medicine quantity:");
	scanf("%f",&b.medi_qty);
	printf("\nenter medicine rate:");
	scanf("%f",&b.medi_rate);
	printf("\ntotal bill:");
	b.total=b.medi_qty*b.medi_rate;
	printf("%f",b.total);
	if(fptr==NULL)
		{
			printf("\tFILE PATH NOT FOUND");
		}
		else
    	{
			fprintf(fptr,"%d\t%s\t%s\t%f\t%f\t%f\t%s\n",b.billno,b.cname,b.mediname,b.medi_qty,b.medi_rate,b.total,b.date);
			printf("\n\t\tINFORMATION ADDED SUCCESSFULLY........");
			fclose(fptr);
		}
}
//==========================================================CASE 2:DISPLAY DATA==================================================
void displaybill()
{
	printf("\t-------------DISPLAY BILL LIST--------------\n");
	printf("\n_________________________________________________________________________________________________________________________________________\n");
	printf("%-10s %-20s %-20s %-20s %-20s %-20s %s","bill no","date","cust name","medicine name","quantity","rate","total");
	printf("\n_________________________________________________________________________________________________________________________________________\n\n");
	fptr=fopen("bill-file.txt","r");
	if(fptr==NULL)
		{
	    	printf("\tFILE PATH NOT FOUND");
		}
		else
		{
			while(fscanf(fptr,"%d%s%s%s%f%f%f",&b.billno,&b.date,&b.cname,&b.mediname,&b.medi_qty,&b.medi_rate,&b.total)!=-1)
	    	{
				printf("%d\t %s\t %s\t %s\t %f\t %f\t %f \n ",b.billno,b.date,b.cname,b.mediname,b.medi_qty,b.medi_rate,b.total);
			}
			printf("_________________________________________________________________________________________________________________________________________\n");
		fclose(fptr);
		}
}
//=======================================================MAIN FUNCTION==================================================================================
int billing()
{
	int choice;
	do{
		printf("\n\n---------------CREATE BILL---------------\n\n");
		printf("\t1:CREATE BILLS\n");
		printf("\t2:DISPLAY BILLS LIST\n");
		printf("\tIF YOU WANT TO EXIT ENTER WRONG CHOICE\n\n");
		printf("\tENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			     bill();
			break;
			case 2:
			     displaybill();
			break;
			default:
				printf("\nIF YOU WANT TO EXIT PRESS 0\n");
				scanf("%d",&choice);
		}
	}while(choice!=0);
}
