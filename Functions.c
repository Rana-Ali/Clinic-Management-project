#include <stdio.h>
#include "std_types.h"
#include <string.h>
#include <stdlib.h>

u8 AvailSlots[][50]={"From 2:00pm to 2:30pm","From 2:30pm to 3:00pm","From 3:00pm to 3:30pm","From 4:00pm to 4:30pm","From 4:30pm to 5:00pm"};
u8 ReservedSlots[5][50];
u8 ReservedSlot_Id[5];
u8 ListLength =0;
u8 slot;
u8 n = 5;
/* n is the number of available slots */
u8 s = 0;
/* s is counter for the ReservedSlots[5][50] and ReservedSlot_Id[5] arrays*/
typedef struct 
{
	u8 Name[20];
	u8 Age;
	u8 Gender[20];
	u8 ID;
	u8 slot[1][50];
}Patient_record;

typedef struct AdminMode
{
	Patient_record Data;
	struct AdminMode*Next;
	
}AdminMode;
void AddPatient ( Patient_record data1);
void EditPatient (u8 id);
u8 IdCheck (u8 id);
void Reserve_slot (u8 id);
void CancelReservation (u8 id);
void ViewPatientRecord(u8 id);
void ViewTodayReservation(void);

AdminMode*HeadAdmin=NULL;
AdminMode*TailAdmin=NULL;

/******************************************/
/******** Admin Mode Functions ************/
/******************************************/

/****************************************************
 * Func Name  :  AddPatient
 * *****************************************************
 * Input Par  : data1 (struct type)
 * Description:Recieve data of patient i want to add to the system
 * Return Val : Void
 * Description: N/A
 * Description: used to add patient to the system
 *
 * ******************************************************
 */
 
void AddPatient (Patient_record data1)
{
	AdminMode*NewPatient=(AdminMode*)malloc(sizeof(AdminMode));
	NewPatient->Data.ID=data1.ID;
	strcpy(NewPatient->Data.Name,data1.Name);
	strcpy(NewPatient->Data.Gender,data1.Gender);
	NewPatient->Data.Age=data1.Age;
	strcpy(NewPatient->Data.slot[0],"No Reservation");
	NewPatient->Next = NULL;
	if(ListLength==0)
	{
		HeadAdmin=TailAdmin=NewPatient;
	}
	else 
	{
		TailAdmin->Next=NewPatient;
		TailAdmin=NewPatient;
	}
	ListLength++;
}
/****************************************************
 * Func Name  :  IdCheck
 * *****************************************************
 * Input Par  : u8 id
 * Description:Recieve ID of patient to check if it is existed or not
 * Return Val : u8
 * Description: unsigned char (1 if not existed , 0 if existed)
 * Description: used check the existance of ID in the system
 *
 * ******************************************************
 */

u8 IdCheck (u8 id)
{
	AdminMode *temp=HeadAdmin;
	while (temp!=NULL)
	{
		if (temp->Data.ID==id)
		{
			return 0;
		}
		temp=temp->Next;
	}
	return 1;
}
void EditPatient (u8 id)
{
	AdminMode *temp=HeadAdmin;
		while (temp != NULL)
	{
		if (temp->Data.ID==id)
		{
			
	     printf("Please enter the new data here:) \n");
	     printf("The new name is :");
	     gets(temp->Data.Name);
		 gets(temp->Data.Name);
		 printf("The new Age is :");
		 scanf("%d",&temp->Data.Age);
		 printf("The new Gender is :");
		 scanf("%s",&temp->Data.Gender);
		 printf("The information have been editted successfully :)\n");
		 return ;
		 
		}
			temp=temp->Next;
	}
}
/****************************************************
 * Func Name  :  Reserve_slot
 * *****************************************************
 * Input Par  : u8 id
 * Description:Recieve ID of patient who i want to reserve a slot for.
 * Return Val : Void
 * Description: N/A
 * Description: used to reserve a slot for a patient from 5 available slots.
 *
 * ******************************************************
 */
void Reserve_slot (u8 id)
{
	/* n is the length of the available slots array */
	printf("The available slots are :\n");
	for(u8 i=0;i<n;i++)
	{
		printf("Press %d for this slot \"%s\"\n",i+1,AvailSlots[i]);
	}
	printf("\nWhich slot you want to reserve ? \n");
	scanf("%d",&slot);
	
	AdminMode*temp=HeadAdmin;
	
	while (temp != NULL)
	{
		if (temp->Data.ID==id)
		{
			strcpy(temp->Data.slot[0],AvailSlots[slot-1]);
		/* add the reserved slot and id to the array of reserved slots */
	           ReservedSlot_Id[s]=temp->Data.ID;
	           strcpy(ReservedSlots[s],temp->Data.slot[0]);
	    /***************************************************************/
		}
		temp = temp -> Next ;
	}


	/*remove the reserved slot from the array of available slots */
	for (u8 j=slot-1;j<n-1;j++)
	{
		strcpy(AvailSlots[j] , AvailSlots[j+1]);
	}
	n--;
	s++;
	
}
/****************************************************
 * Func Name  :  CancelReservation
 * *****************************************************
 * Input Par  : u8 id
 * Description:Recieve ID of patient i want to cancel thw reservation for.
 * Return Val : Void
 * Description: N/A
 * Description: used to cancel the reservation for a patient.
 *
 * ******************************************************
 */
void CancelReservation (u8 id)
{
	AdminMode*temp=HeadAdmin;
	while (temp != NULL)
	{
		if (temp->Data.ID==id)
		{
		/* delete this ID and its slot from the array of IDs of rserves slots */
					for (u8 x=0;x<5;x++)
		{
			if (temp->Data.ID==ReservedSlot_Id[x])
			{
					for (u8 j=x;j<s-1;j++)
	            {
		           ReservedSlot_Id[j] = ReservedSlot_Id[j+1];
				   strcpy(ReservedSlots[j] , ReservedSlots[j+1]);
	            }
				s--;
			}
		}
			
			
		/* cancel the slot and return it to the available slots */
			strcpy(AvailSlots[n],temp->Data.slot[0]);
			strcpy(temp->Data.slot[0],"No Reservation");
			n++;
		}
		temp = temp->Next;
	}

}

/*****************************************/
/**********User mode functions************/
/*****************************************/

/****************************************************
 * Func Name  :  ViewPatientRecord
 * *****************************************************
 * Input Par  : u8 id
 * Description:Recieve ID of patient i want to view his information.
 * Return Val : Void
 * Description: N/A
 * Description: used to view the information of a patient on the system
 *
 * ******************************************************
 */
void ViewPatientRecord(u8 id)
{
	AdminMode*temp=HeadAdmin;
	while (temp != NULL)
	{
		if (temp->Data.ID==id)
		{
			printf("Name          : %s\n",temp->Data.Name);
			printf("Age           : %d\n",temp->Data.Age);
			printf("Gender        : %s\n",temp->Data.Gender);
			printf("Reserved slot : %s\n",temp->Data.slot[0]);		
		}
		temp = temp -> Next;
	}
	
}

/****************************************************
 * Func Name  :  ViewTodayReservation
 * *****************************************************
 * Input Par  : void
 * Description: N/A
 * Return Val : Void
 * Description: N/A
 * Description: used to view the today's reservations on the system.
 *
 * ******************************************************
 */

void ViewTodayReservation(void)
{
	for (u8 i =0;i<s;i++)
	{
printf("ID is %d and the reserved slot is %s\n",ReservedSlot_Id[i],ReservedSlots[i]);
	}
	
}