#include<stdio.h>
#include "std_types.h"
#include "clinic.h"
#include <string.h>
#include <stdlib.h>
u32 pass = 1234;
u8 ID_input;
u32 input,pass_input,admin_input,user_input;
int main(void)
{
	/*The default password for admin mode is 1234*/
	u8 flag1 =1;  
	while (flag1){
		/*flag1 is for external program to continue */
	printf("For admin mode press 1\nFor user mode press 2\nTo close program press 0\n");
	scanf("%d",&input);
	switch (input)
	{
		case 0:{ flag1 =0; break;}
		case 1: 
		{
			printf("Please enter the password :");
			scanf("%d",&pass_input);
			printf("%d",pass_input);
			printf("\n%d\n",pass);
			for (u32 i=0;i<2;i++)
			{
				if (pass_input != pass)
				{
				printf("you entered wrong password please try again :");
				scanf("%d",&pass_input);
				}
				else 
				{
				 break;
				}
			}
			if (pass_input != pass)
			{
			printf("you entered wrong password for three times :)");
			flag1=0;
			}
			else {
				u8 flag2=1;
				while (flag2) {
					/* flag2 is for admin mode to continue */
				printf("1-To add patient record press 1\n2-To edit patient record press 2\n3-To reserve a slot with a doctor press 3\n4-To cancel a reservation press 4\n5-nTo exit from admin mode press 0\nYour input is :");
			    scanf("%d",&admin_input);
				switch (admin_input)
				{
					case 0: flag2=0; break;
					case 1: 
					{
						printf("Please enter the ID: ");
						scanf("%d",&ID_input);
						if (IdCheck(ID_input))
						{
							Patient_record data1;
							printf("Please enter Name:");
						    gets(data1.Name);
							gets(data1.Name);
							printf("Please enter Age:");
							scanf("%d",&data1.Age);
							printf("Please enter Gender:");
							scanf("%s",&data1.Gender);
							data1.ID=ID_input;
							AddPatient(data1);
							printf("\nPatient added successfully\n");
						
						}
						else 
						{
							printf("\n\nThis ID must be unique please try again\n\n");
							break;
						}
						
					}
					break;
					case 2:
					{
						printf("Please enter the ID : ");
						scanf("%d",&ID_input);
						if (IdCheck(ID_input))
						{
						     printf("\n\nThis ID is not existed please try again\n\n");
						}
						else
						{
							 EditPatient(ID_input); 
						}
					}
					break;
					case 3: 
					{
						printf("Please enter the ID : ");
						scanf("%d",&ID_input);
						if (IdCheck(ID_input))
						{
						     printf("\n\nThis ID is not existed please try again\n\n");
						}
						else
						{
					    Reserve_slot(ID_input);
						}
					}
					break;
					case 4:
					{
                        printf("Please enter the ID : ");
						scanf("%d",&ID_input);
						if (IdCheck(ID_input))
						{
						     printf("\n\nThis ID is not existed please try again\n\n");
						}
						else
						{
						CancelReservation(ID_input);
						}
					}
					break;
					default: printf("\n\nPlease enter a valid input\n\n");
					break;
				}
				}
				
			}
			
		}
		break;
		case 2:
		{
		/*flag3 is to continue the user mode in the program */
		u8 flag3=1;
		while (flag3)
		{
				printf("1-To view patient record press 1\n2-To view today's reservations press 2\n3-nTo exit from user mode press 0\nYour input is :");
			    scanf("%d",&user_input);
				switch (user_input)
				{
					case 0: flag3=0; break;
					case 1:
					{
						printf("Please enter the ID : ");
						scanf("%d",&ID_input);
						if (IdCheck(ID_input))
						{
						     printf("\n\nThis ID is not existed please try again\n\n");
						}
						else
						{
							  ViewPatientRecord(ID_input); 
						}
					} break;
					case 2:
					{
						printf("Today's Reservations are :\n");
						 ViewTodayReservation();
					}
					break;
				}
		}
		break;
		}
		default: printf("please enter a valid input\n\n");
		break;
	}
}
}
