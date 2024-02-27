#include<stdio.h>
#include<string.h>
struct customer{
	int cust_id;
	char cust_name[90];
	long long int mob_no;
	char city[90];
	char email[90];
};
struct customer c;
FILE *fptr;
//=======================================CASE 1:CREATE DATA==================================================
void createcustomer()
{
	printf("ENTER CUSTOMER INFPRMATION\n");
	fptr=fopen("customer-file.txt","a");
	printf("\nenter customer id:");
	scanf("%d",&c.cust_id);
	printf("\nenter customer name:");
	scanf("%s",&c.cust_name);
	printf("\nenter mobile number:");
	scanf("%lld",&c.mob_no);
	printf("\nenter city name:");
	scanf("%s",&c.city);
	printf("\nenter customer email id:");
	scanf("%s",&c.email);
	if(fptr==NULL)
		{
			printf("\tFILE PATH NOT FOUND");
		}
		else
    	{
			fprintf(fptr,"%d\t%s\t\t%lld\t%s\t%s\n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);
			printf("\n\t\tINFORMATION ADDED SUCCESSFULLY........");
			fclose(fptr);
		}
}
//==========================================================CASE 2:DISPLAY DATA==================================================
void displaycustomer()
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
//=====================================================CASE 3:SEARCH BY ID AND NAME================================================================
int searchcustomer()
{
	int choice,found;
	do{
	printf("\n1:SEARCH BY ID\n");
	printf("2:SEARCH BY NAME\n");
	printf("\nENTER YOUR CHOICE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
		break;
		case 1:
			int cid;
	  		printf("enter customer id:\n");
			scanf("%d",&cid);
			fptr=fopen("customer-file.txt","r");
			while(fscanf(fptr,"%d%s%lld%s%s",&c.cust_id,&c.cust_name,&c.mob_no,&c.city,&c.email)!=-1)
			{	
     			if(c.cust_id==cid)
				{	
					found=1;
					printf("<-------------customer found------->\n\n");
					printf("%-10d %-20s %-20lld %-20s %s\n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);
					printf("_______________________________________________________________________________________________________________________________");
					fclose(fptr);
		    		break;
				}
			}
			if(!found){
				printf("\t\nDATA NOT FOUND\n");
			}
		break;
		case 2:
			char ch[90];
			printf("enter customer name:");
			scanf("%s",&ch);
			fptr=fopen("customer-file.txt","r");
			while(fscanf(fptr,"%d%s%lld%s%s",&c.cust_id,&c.cust_name,&c.mob_no,&c.city,&c.email)!=-1)
			{
     			if(strcmp(c.cust_name,ch)==0)
				{ 
					found=1;
					printf("<--------------customer found---------------->\n\n");
					printf("%-10d %-20s %-20lld %-20s %s\n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);
					printf("________________________________________________________________________________________________________________________________\n");
					fclose(fptr);
		    		break;
				}
			}
			if(!found)
			{
				printf("\nDATA NOT FOUND\n");
			}

		break;
	}
	printf("\nIF YOU WANT TO EXIT PRESS 0");
	}while(choice!=0);
}
//=======================================================CASE 4:CUSTOMER UPDATE======================================================================
void Updatecustomer()
{	
	FILE *fptr2;
	int sid;
	fptr=fopen("customer-file.txt","r+");
	fptr2=fopen("copy.txt","a+");
	if(fptr==NULL)
	{
		printf("\n\n<----------------NO DATA AVIALABLE!------------------->\n\n");
	}
	else
	{	printf("\nEnter customer id : ");
		scanf("%d",&sid);
		while(fscanf(fptr,"%d%s%lld%s%s",&c.cust_id,&c.cust_name,&c.mob_no,&c.city,&c.email)!=-1)
		{	
			if(sid!=c.cust_id)
			{
				fprintf(fptr2,"%d\t%s\t%lld\t%s\t%s \n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);	
			}
			else
			{
				printf("\nEnter New ID : ");
				scanf("%d",&c.cust_id);
				printf("\nEnter New Name : ");
				scanf("%s",&c.cust_name);
				printf("\nEnter New Mobile number : ");
				scanf("%lld",&c.mob_no);
				printf("\nenter new city name:");
				scanf("%s",&c.city);
				printf("\nEnter New Email : ");
				scanf("%s",&c.email);
				fprintf(fptr2,"%d\t%s\t%lld\t%s\t%s \n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);
			}
		}			
			fclose(fptr);
			fclose(fptr2);
			remove("customer-file.txt");
			rename("copy.txt","customer-file.txt");
			printf("\nUPDATED\n");
		}
}
//=======================================================CASE 5:DELETE CUSTOMER================================================================
void deletecustomer()
{
		int cid,found=0;
		FILE *fptr2;
	  	printf("enter customer id:\n");
		scanf("%d",&cid);
		fptr=fopen("customer-file.txt","r");
		fptr2=fopen("copy.txt","a+");
		while(fscanf(fptr,"%d%s%lld%s%s",&c.cust_id,&c.cust_name,&c.mob_no,&c.city,&c.email)!=-1)
			{	
     			if(c.cust_id==cid)
				{	
					found=1;
				}
				else
				{
					fprintf(fptr2,"%d\t%s\t%lld\t%s\t%s \n",c.cust_id,c.cust_name,c.mob_no,c.city,c.email);	
				}
			}
			fclose(fptr);
			fclose(fptr2);
			if(found){
				remove("customer-file.txt");
				rename("copy.txt","customer-file.txt");
				printf("\n\t\tRecord deleted Successfully\n");
			}else
			{
				printf("\n\t<---------------------Record not found----------------------->\n");
			}
}
//=======================================================MAIN FUNCTION=========================================================================
int customer_info()
{
	int choice;
	do{
		printf("\n\n---------------INFORMATION ABOUT CUSTOMER---------------\n\n");
		printf("\t1:ENTER CUSTOMER INFOMATION\n");
		printf("\t2:DISPLAY CUSTOMER LIST\n");
		printf("\t3:SEARCH DATA IN FILE\n");
		printf("\t4:CUSTOMER UPDATE\n");
		printf("\t5:DELETE CUSTOMER INFO\n");
		printf("\tIF YOU WANT TO EXIT ENTER WRONG CHOICE\n\n");
		printf("\tENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			     createcustomer();
			break;
			case 2:
			     displaycustomer();
			break;
			case 3:
				searchcustomer();
			break;
			case 4:
				Updatecustomer();
			break;
			case 5:
				deletecustomer();
			break;
			default:
		printf("\t\nIF YOU WANT TO EXIT PRESS 0\n");
		scanf("%d",&choice);
	}
	}while(choice!=0);
}

