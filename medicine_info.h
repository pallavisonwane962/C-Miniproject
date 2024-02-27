#include<stdio.h>
#include<string.h>
struct medicine{
	char medi_name[90];
	int medi_id,rack_no,quantity,sale,bought,cost,profit,buy,bill_no;
	float unit;
	char pur_date[90],exp_date[90],manu_date[90];
	char comp_name[90];
	char supp_name[90];
};
struct medicine m;
//FILE *fptr;
//===========================================================CASE 1:CREATE MEDICINE INFO===================================================================
void medicineentry()
{
	printf("ENTER MEDICINE INFPRMATION\n");
	fptr=fopen("medicine-file.txt","a");
	printf("\nENTER MEDICIN ID:");
	scanf("%d",&m.medi_id);
	printf("\nENTER MEDICINE NAME:");
	scanf("%s",m.medi_name);
	printf("\nENTER RACK NUMBER:");
	scanf("%d",&m.rack_no);
	printf("\nENTER MEDICINE QUANTITY:");
	scanf("%d",&m.quantity);
	printf("\nENTER TOTAL SALES MEDICINE:");
	scanf("%d",&m.sale);
	printf("\nTOTAL QUANTITY BOUGHT:");
	scanf("%d",&m.bought);
	printf("\nENTER MEDICINE UNIT:");
	scanf("%f",&m.unit);
	printf("\nENTER EACH COST OF MEDICINE:");
	scanf("%d",&m.cost);
	printf("\nENTER PERCHASE DATE:");
	scanf("%s",&m.pur_date);
	printf("\nENTER MANIFACTURE DATE");
	scanf("%s",&m.manu_date);
	printf("\nENTER EXPIRE DATE:");
	scanf("%s",&m.exp_date);
	printf("\nENTER COMPANY NAME:");
	scanf("%s",m.comp_name);
	printf("\nENTER SUPPLIER NAME:");
	scanf("%s",m.supp_name);
	printf("\nENTER BILL NUMBER:");
	scanf("%d",&m.bill_no);
	if(fptr==NULL)
		{	
			printf("\tFILE PATH NOT FOUND");
		}
			else
    	{  
			 fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",m.medi_id,m.medi_name,m.rack_no,m.quantity,m.sale,m.bought,m.unit,m.cost,m.pur_date,m.manu_date,m.exp_date,m.comp_name,m.supp_name,m.bill_no);
			printf("\n\t\tINFORMATION ADDED SUCCESSFULLY........");
			fclose(fptr);
		}  
	}
//============================================================case 2:display medicine info==================================================================
void viewstock()
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
//=============================================================CASE 3:UPDATE DATA=========================================================================
void updatestock()
{	
	FILE *fptr2;
	int id;
	fptr=fopen("medicine-file.txt","r+");
	fptr2=fopen("copy.txt","a+");
	if(fptr==NULL)
	{
		printf("\n\n<----------------NO DATA AVIALABLE!------------------->\n\n");
	}
	else
	{	printf("\nEnter medicine id : ");
		scanf("%d",&id);
		while(fscanf(fptr,"%d%s%d%d%d%d%f%d%s%s%s%s%s%d",&m.medi_id,&m.medi_name,&m.rack_no,&m.quantity,&m.sale,&m.bought,&m.unit,&m.cost,&m.pur_date,&m.manu_date,&m.exp_date,&m.comp_name,&m.supp_name,&m.bill_no)!=-1)
		{	
			if(id!=m.medi_id)
			{
				 fprintf(fptr2,"%d\t%s\t%d\t%d\t%d\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",m.medi_id,m.medi_name,m.rack_no,m.quantity,m.sale,m.bought,m.unit,m.cost,m.pur_date,m.manu_date,m.exp_date,m.comp_name,m.supp_name,m.bill_no);
			}
			else
			{
					printf("\nENTER NEW MEDICIN ID:");
					scanf("%d",&m.medi_id);
					printf("\nENTER NEW MEDICINE NAME:");
					scanf("%s",&m.medi_name);
					printf("\nENTER NEW RACK NUMBER:");
					scanf("%d",&m.rack_no);
					printf("\nENTER NEW MEDICINE QUANTITY:");
					scanf("%d",&m.quantity);
					printf("\nENTER NEW TOTAL SALES MEDICINE:");
					scanf("%d",&m.sale);
					printf("\nTOTAL NEW QUANTITY BOUGHT:");
					scanf("%d",&m.bought);
					printf("\nENTER NEW MEDICINE UNIT:");
					scanf("%f",&m.unit);
					printf("\nENTER NEW COST OF MEDICINE:");
					scanf("%d",&m.cost);
					printf("\nENTER NEW PERCHASE DATE:");
					scanf("%s",&m.pur_date);
					printf("\nENTER NEWMANIFACTURE DATE");
					scanf("%s",&m.manu_date);
					printf("\nENTER NEW EXPIRE DATE:");
					scanf("%s",&m.exp_date);
					printf("\nENTER NEW COMPANY NAME:");
					scanf("%s",&m.comp_name);
					printf("\nENTER NEW SUPPLIER NAME:");
					scanf("%s",&m.supp_name);
					printf("\nENTER NEW BILL NUMBER:");
					scanf("%d",&m.bill_no);
				 fprintf(fptr2,"%d\t%s\t%d\t%d\t%d\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",m.medi_id,m.medi_name,m.rack_no,m.quantity,m.sale,m.bought,m.unit,m.cost,m.pur_date,m.manu_date,m.exp_date,m.comp_name,m.supp_name,m.bill_no);
			}
		}			
			fclose(fptr);
			fclose(fptr2);
			remove("medicine-file.txt");
			rename("copy.txt","AB.txt");
			printf("\nUPDATED\n");
		}
}
//============================================================CASE 4:SEARCH DATA=========================================================================
void searchmedicine()
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
				  		printf("enter medicine id:\n");
						scanf("%d",&id);
						fptr=fopen("medicine-file.txt","r");
							while(fscanf(fptr,"%d%s%d%d%d%d%f%d%s%s%s%s%s%d",&m.medi_id,&m.medi_name,&m.rack_no,&m.quantity,&m.sale,&m.bought,&m.unit,&m.cost,&m.pur_date,&m.manu_date,&m.exp_date,&m.comp_name,&m.supp_name,&m.bill_no)!=-1)
						{	
			     			if(m.medi_id==id)
							{	
								found=1;
								printf("medicine found\n");
									printf("%-10d %-15s %-10d %-10d %-10d %-10d %-15f %-10d %-15s %-15s %-15s %-15s %-15s %-10d\n",m.medi_id,m.medi_name,m.rack_no,m.quantity,m.sale,m.bought,m.unit,m.cost,m.pur_date,m.manu_date,m.exp_date,m.comp_name,m.supp_name,m.bill_no);
								printf("_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
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
						printf("enter medicine name:");
						scanf("%s",&ch);
						fptr=fopen("medicine-file.txt","r");
							while(fscanf(fptr,"%d%s%d%d%d%d%f%d%s%s%s%s%s%d",&m.medi_id,&m.medi_name,&m.rack_no,&m.quantity,&m.sale,&m.bought,&m.unit,&m.cost,&m.pur_date,&m.manu_date,&m.exp_date,&m.comp_name,&m.supp_name,&m.bill_no)!=-1)
						{
			     			if(strcmp(m.medi_name,ch)==0)
							{ 
								found=1;
								printf("customer found\n");
									printf("%-10d %-15s %-10d %-10d %-10d %-10d %-15f %-10d %-15s %-15s %-15s %-15s %-15s %-10d\n",m.medi_id,m.medi_name,m.rack_no,m.quantity,m.sale,m.bought,m.unit,m.cost,m.pur_date,m.manu_date,m.exp_date,m.comp_name,m.supp_name,m.bill_no);
								printf("________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
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
//============================================================CASE 5:VIEW STOCK============================================================================
void viewsales()
{
	fptr=fopen("medicine-file.txt","r");
	if(fptr==NULL)
	{
		printf("\n\n<----------------NO DATA AVIALABLE!------------------->\n\n");
	}
  else
	{	
		printf("\n<<_____________________________________________________________________________________________________________________________>>\n");
		while(fscanf(fptr,"%d%s%d%d%d%d%f%d%s%s%s%s%s%d",&m.medi_id,&m.medi_name,&m.rack_no,&m.quantity,&m.sale,&m.bought,&m.unit,&m.cost,&m.pur_date,&m.manu_date,&m.exp_date,&m.comp_name,&m.supp_name,&m.bill_no)!=-1)
		{	
			printf("\tId           : %d\n",m.medi_id);
			printf("\tName of Medicine     : %s\n",m.medi_name);
			printf("\tTotal Tablets Bought : %d\n",m.bought);
			printf("\tAvailable Quantity   : %d\n",m.quantity);
			printf("\tSaled Tablets        : %d\n",m.sale);	
		printf("\n<<_____________________________________________________________________________________________________________________________>>\n");	
				}
				fclose(fptr);
			}
}
//===========================================================MAIN FUNCTION=================================================================================
int	medicine_info()
{
	 int choice;
	 do{
	 	printf("\n\n-------------------INFORMATION ABOUT MEDICINE------------------------\n\n");
		printf("1:ENTER MEDICINE INFORMATION\n");
		printf("2:VIEW MEDICINE STOCK\n");	 
		printf("3:UPDATE MEDICINE STOCK\n");
		printf("4:SEARCH MEDICINE STOCK \n");
		printf("5:MEDICINE SALE VIEW\n");
		printf("\tIF YOU WANT TO EXIT ENTER WRONG CHOICE\n\n");	
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				medicineentry();
			break;
			case 2:
				viewstock();
			break;
			case 3:
				updatestock();
			break;
			case 4:
				searchmedicine();
			break;
			case 5:
				viewsales();
			break;
			default:
				printf("\nIF YOU WANT TO EXIT PRESS 0\n");
				scanf("%d",&choice);
		}
	 }while(choice!=0);
}

