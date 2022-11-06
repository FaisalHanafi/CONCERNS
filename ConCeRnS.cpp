// Program for Lab Test

// Matric No:
// Name: 
//Section:

#include <iostream>
#include <iomanip>
using namespace std;

// Constant definitions
#define BAKINGCOURSE 750.00
#define PASTACOURSE 800.00
#define EVENINGEXTRA 50.00
#define GROUPDISCOUNT 0.1
#define GST 0.06


//declare all function protypes here 
int getCourseTime();
int getCourseType();
int getNumParticipants();
void processRegistration (int, int, int);

int main(){
	
	int classcode, coursetime, numparticipants;
	
	cout<<"\tWELCOME TO ONE COOKING ACADEMY"<<endl<<endl<<endl;
	
	classcode = getCourseType();
	coursetime = getCourseTime();
	numparticipants = getNumParticipants();
	processRegistration (classcode, coursetime, numparticipants);
		
	cout <<endl<< "HAVE FUN COOKING!!!" <<endl;
		
	return 0;
}


int getCourseType()
{
	int type;
	
	do
	{
	cout<<endl<<"\nAvailable Cooking courses offered:"<<endl;
	cout<<"1 - Bread Baking course (RM 750 per person)" <<endl;
	cout<<"2 - Pasta Cooking course (RM 800 per person)" <<endl;
	cout<<"Choose preferred course: ";
	cin>> type;
	if (type !=1 && type!=2)
		cout <<"Try again."<<endl;
	}
	while (type!=1 && type!=2);
	return type;
}

int getCourseTime()
{
	int time;
	cout<<endl<<"Preferred time for course:"<<endl;
	cout<<"1 - Morning" <<endl;
	cout<<"2 - Evening" <<endl;
	cout<<"Choose 1 or 2: ";
	cin>> time;
	return time;
}


int getNumParticipants()
{
	int num;
	cout<<"\nEnter the number of participants: ";
	cin>> num;
	return num;
}

void processRegistration (int type, int time, int num)
{
	float coursefees, extrafees = 0, totalfees;
	float discount;
	
	cout<<endl<<"Registering "<<num<< " participants for ";
	if (type == 1)
	{
		coursefees = BAKINGCOURSE * num;
		cout<<"Bread Baking Course";
	}
	else
	{
		coursefees = PASTACOURSE * num;
		cout<<"Pasta Cooking Course";
	}
	
	cout<<" conducted in the ";
	
	if (time==2)
	{
		cout<<"evening."<<endl;
		extrafees = EVENINGEXTRA*num;
	}
	else
		cout<<"morning."<<endl;
	
	totalfees = coursefees + extrafees;
	cout<<endl<<"Summary of charges:"<<endl<<endl;

	cout<<"Course Fees\tRM "<<coursefees<<endl;
	cout<<"Extra Fees\tRM "<<extrafees<<endl;
        
    if (num >= 5)
    	totalfees *= (1-GROUPDISCOUNT);
    	
	cout<<"Total\t\tRM "<< totalfees<<endl;
	cout<<"GST\t\tRM "<< totalfees*GST<<endl;

	cout<<"Total amount	RM "<<totalfees* (1+GST)<<endl<<endl;

	cout<<"THANK YOU FOR USING THIS SYSTEM :)"<<endl;

	return;
}


