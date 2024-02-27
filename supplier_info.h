#include<stdio.h>
#include<string.h>
struct supplier{
	int supp_id;
	char supp_name[90];
	long long int supp_mob_no;
	char supp_city[90];
	char supp_email[90];
};
struct supplier s;
//=======================================CASE 1:CREATE DATA==================================================
void  supp_entry()
{
	printf("ENTER SUPPLIER INFPRMATION\n");
	fptr=fopen("supplier-file.txt","a");
	printf("\nenter supplier id:");
	scanf("%d",&s.supp_id);
	printf("\nenter supplier name:");
	scanf("%d",s.supp_name);
	printf("\nenter mobile number:");
	scanf("%lld",&s.supp_mob_no);
	printf("\nenter city name:");
	scanf("%s",&s.supp_city);
	printf("\nenter supplier email id:");
	scanf("%s",&s.supp_email);
	if(fptr==NULL)
		{
			printf("\tFILE PATH NOT FOUND");
		}
		else
    	{
			fprintf(fptr,"%d\t%s\t\t%lld\t%s\t%s\n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);
			printf("\n\t\tINFORMATION ADDED SUCCESSFULLY........");
			fclose(fptr);
		}
}
//==========================================================CASE 2:DISPLAY DATA==================================================
void supp_list()
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
//=====================================================CASE 3:SEARCH BY NAME AND ID================================================================
void supp_search()
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
			int id;
	  		printf("enter supplier id:\n");
			scanf("%d",&id);
			fptr=fopen("supplier-file.txt","r");
			while(fscanf(fptr,"%d%s%lld%s%s",&s.supp_id,&s.supp_name,&s.supp_mob_no,&s.supp_city,&s.supp_email)!=-1)
			{	
     			if(s.supp_id==id)
				{	
					found=1;
					printf("<-------------supplier found------->\n\n");
					printf("%-10d %-20s %-20lld %-20s %s\n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);
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
			printf("enter supplier name:");
			scanf("%s",&ch);
			fptr=fopen("supplier-file.txt","r");
			while(fscanf(fptr,"%d%s%lld%s%s",&s.supp_id,&s.supp_name,&s.supp_mob_no,&s.supp_city,&s.supp_email)!=-1)
			{
     			if(strcmp(s.supp_name,ch)==0)
				{ 
					found=1;
					printf("supplier found\n");
					printf("%-10d %-20s %-20lld %-20s %s\n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);
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
//=======================================================CASE 4:UPDATE SUPPLIER======================================================================
void supp_update()
{	
	FILE *fptr2;
	int sid;
	fptr=fopen("supplier-file.txt","r+");
	fptr2=fopen("copy.txt","a+");
	if(fptr==NULL)
	{
		printf("\n\n<----------------NO DATA AVIALABLE!------------------->\n\n");
	}
	else
	{	printf("\nEnter supplier id : ");
		scanf("%d",&sid);
		while(fscanf(fptr,"%d%s%lld%s%s",&s.supp_id,&s.supp_name,&s.supp_mob_no,&s.supp_city,&s.supp_email)!=-1)
		{	
			if(sid!=s.supp_id)
			{
				fprintf(fptr2,"%d\t%s\t%lld\t%s\t%s \n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);	
			}
			else
			{
				printf("\nEnter New id : ");
				scanf("%d",&s.supp_id);
				printf("\nEnter New Name : ");
				scanf("%s",&s.supp_name);
				printf("\nEnter New Mobile number : ");
				scanf("%lld",&s.supp_mob_no);
				printf("\nenter new city:");
				scanf("%s",&s.supp_city);
				printf("\nEnter New Email : ");
				scanf("%s",&s.supp_email);
				fprintf(fptr2,"%d\t%s\t%lld\t%s\t%s \n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);
			}
		}			
			fclose(fptr);
			fclose(fptr2);
			remove("supplier-file.txt");
			rename("copy.txt","supplier-file.txt");
			printf("\nUPDATED\n");
		}
}
//================================================================CASE 5:DELETE DATA===================================================================
void supp_delete()
{
		int id,found=0;
		FILE *fptr2;
	  	printf("enter supplier id:\n");
		scanf("%d",&id);
		fptr=fopen("supplier-file.txt","r");
		fptr2=fopen("copy.txt","a+");
		while(fscanf(fptr,"%d%s%lld%s%s",&s.supp_id,&s.supp_name,&s.supp_mob_no,&s.supp_city,&s.supp_email)!=-1)
			{	
     			if(s.supp_id==id)
				{	
					found=1;
				}
				else
				{
					fprintf(fptr2,"%d\t%s\t%lld\t%s\t%s \n",s.supp_id,s.supp_name,s.supp_mob_no,s.supp_city,s.supp_email);	
				}
			}
			fclose(fptr);
			fclose(fptr2);
			if(found){
				remove("supplier-file.txt");
				rename("copy.txt","supplier-file.txt");
				printf("\n\t\tRecord deleted Successfully\n");
			}else
			{
				printf("\n\t<---------------------Record not found----------------------->\n");
			}
}
//================================================================MAIN FUNCTION=========================================================================
int supplier_info()
{
	int choice;
	do{
		printf("\n\n---------------INFORMATION ABOUT SUPPLIER---------------\n\n");
		printf("\t1:ENTER SUPPLIER INFOMATION\n");
		printf("\t2:DISPLAY SUPPLIER LIST\n");
		printf("\t3:SEARCH SUPPLIER DATA IN FILE\n");
		printf("\t4:UPDATE SUPPLIER DATA\n");
		printf("\t5:DELETE SUPPLIER DATA\n");
		printf("\tIF YOU WANT TO EXIT ENTER WRONG CHOICE\n\n");
		printf("\tENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			     supp_entry();
			break;
			case 2:
			     supp_list();
			break;
			case 3:
				supp_search();
			break;
			case 4:
				supp_update();
			break;
			case 5:
				supp_delete();
			break;
			default:
				printf("\nIF YOU WANT TO EXIT PRESS 0\n");
				scanf("%d",&choice);
		}
	}while(choice!=0);
}
