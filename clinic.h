#ifndef CLINIC_H
#define CLINIC_H
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

u8 IdCheck (u8 id);
void AddPatient ( Patient_record data1);
void EditPatient (u8 id);
void Reserve_slot (u8 id);
void CancelReservation (u8 id);
void ViewPatientRecord(u8 id);
void ViewTodayReservation(void);

#endif 






