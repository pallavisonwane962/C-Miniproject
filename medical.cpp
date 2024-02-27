#include<stdio.h>
#include"customer_info.h"
#include"medicine_info.h"
#include"supplier_info.h"
#include"billing.h"
#include"about.h"
int main()
{
	
		int choice;
	do{
		printf("\n================================================================================\n");
		printf("------------------------MENU------------------------------\n");
		printf("\t1:INFORMATION ABOUT CUSTOMER\n");
		printf("\t2:MEDICINE MENU\n");
		printf("\t3:INFORMATION OF SUPPLIER\n");
		printf("\t4:BILLING IN MEDICAL\n");
		printf("\t5:ABOUT MENU\n");
		printf("\t6:EXIT\n\n");
		printf("\tENTER YOUR CHOICE:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				customer_info();
			break;
			case 2:
				medicine_info();
			break;
			case 3:
				supplier_info();
			break;
			case 4:
				billing();
			break;
			case 5:
				about();
			break;
			case 6:
				printf("enter 0 to exit:");
				scanf("%d",&choice);
			break;
			default :
			   printf("WRONG CHOICE");
		}
	}while(choice!=0);
	return 0;
}
