#include<stdio.h>
struct about{
	char ch[90];
};
struct about a;
void customer()
{
	printf("\t-------------DISPLAY CUSTOMER LIST--------------\n");
	printf("\n_________________________________________________________________________________________________________________________________________\n");
	printf("%-10s %-20s %-20s %-20s %s","cust id","cust name","mobile no","city","email");
	printf("\n_________________________________________________________________________________________________________________________________________\n\n");
	fptr=fopen("customer-file.txt","r");
	if(fptr==NULL)
		{
	    	printf("\tFILE PATH NOT FOUND");
		}
		else
		{
			while(fscanf(fptr,"%d%s%lld%s%s",&c.cust_id,&c.cust_name,&c.mob_no,&c.city,&c.email)!=-1)
	    	{
				printf("%-10d %-20s %-20lld %-20s %s\n\n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);
			}
			printf("_________________________________________________________________________________________________________________________________________\n");
		fclose(fptr);
		}
}
void Medicine()
{
	printf("\t-----------------------------------------------------------DISPLAY MEDICINE LIST----------------------------------------------\n\n");
	printf("___________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf("%-10s %-15s %-10s %-10s %-10s %-10s %-15s %-10s %-15s %-15s %-15s %-15s %-15s %-10s\n","medi id","medicine name","rack no","quantity","sale","bought","unit","cost","p date","m date","e date","com name","supp name","bill no");
	printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");
	fptr=fopen("medicine-file.txt","r");
	if(fptr==NULL)
		{
	    	printf("\tFILE PATH NOT FOUND");
		}
		else
		{
			while(fscanf(fptr,"%d%s%d%d%d%d%f%d%s%s%s%s%s%d",&m.medi_id,&m.medi_name,&m.rack_no,&m.quantity,&m.sale,&m.bought,&m.unit,&m.cost,&m.pur_date,&m.manu_date,&m.exp_date,&m.comp_name,&m.supp_name,&m.bill_no)!=-1)
	    	{
				printf("%-10d %-15s %-10d %-10d %-10d %-10d %-15f %-10d %-15s %-15s %-15s %-15s %-15s %-10d\n\n",m.medi_id,m.medi_name,m.rack_no,m.quantity,m.sale,m.bought,m.unit,m.cost,m.pur_date,m.manu_date,m.exp_date,m.comp_name,m.supp_name,m.bill_no);
			}
			printf("____________________________________________________________________________________________________________________________________________________________________________________\n");
		fclose(fptr);
		}
}
void Supplire()
{
		printf("\t-------------DISPLAY SUPPLIER LIST--------------\n");
	printf("\n_________________________________________________________________________________________________________________________________________\n");
	printf("%-10s %-20s %-20s %-20s %s","supp id","supp name","mobile no","city","email");
	printf("\n_________________________________________________________________________________________________________________________________________\n\n");
	fptr=fopen("supplier-file.txt","r");
	if(fptr==NULL)
		{
	    	printf("\tFILE PATH NOT FOUND");
		}
		else
		{
			while(fscanf(fptr,"%d%s%lld%s%s",&s.supp_id,&s.supp_name,&s.supp_mob_no,&s.supp_city,&s.supp_email)!=-1)
	    	{
				printf("%-10d %-20s %-20lld %-20s %s\n\n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);
			}
			printf("_________________________________________________________________________________________________________________________________________\n");
		fclose(fptr);
		}
}
int about()
{
	int choice;
	do{
		printf("\n\n---------------ABOUT MENU---------------\n\n");
		printf("\t1: ABOUT CUSTOMER INFORMATION\n");
		printf("\t2:ABOUT MEDICINE INFORMATION\n");
		printf("\t3:ABOUT SUPPLIER INFORMATION\n");
		printf("\t4:ABOUT BILLING\n");
		printf("\tIF YOU WANT TO EXIT ENTER WRONG CHOICE\n\n");
		printf("\tENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			    customer();
			break;
			case 2:
				Medicine();
			break;
			case 3:
				Supplire();
			break;
			case 4:
			
			break;
			default:
				printf("\nIF YOU WANT TO EXIT PRESS 0\n");
				scanf("%d",&choice);
		}
	}while(choice!=0);
}
