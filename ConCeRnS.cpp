#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Constant definitions
#define BAKINGCOURSE 750.00
#define PASTACOURSE 800.00
#define EVENINGEXTRA 50.00
#define GROUPDISCOUNT 0.1
#define GST 0.06


//Function declarations
bool loginInfo();
int getCourseTime();
int getCourseType();
int getNumParticipants();
void processRegistration (int, int, int);

int main(){
	
	int option,classcode, coursetime, numparticipants;
	bool login;
	
	cout<<"\tWELCOME TO ONE COOKING ACADEMY"<<endl<<endl<<endl;

	int choice;
	cout << "\nPlease choose whether you want to login or register. \n";
	cout << "1:Register \n2:Login \n";
	cout << "Your choice: ";
	cin >> choice;

	if (choice == 1)
	{
		string password, username;

		cout << "\nPlease enter your username: ";
		cin >> username;
		cout << "\nPlease enter your password: ";
		cin >> password;
		cout << "\n\n" <<endl;

		std::ofstream file;

		file.open("file.txt");

		file << username << endl;
		file << password;

		file.close();
		main();
	}
	
	else if (choice == 2)
	{
		login = loginInfo();

		if (!login)
		{
			cout <<"You had entered an incorrect username or password, please try again!" << endl;
			system("PAUSE");
			cout << "\n\n" <<endl;
			exit(0);
		}
		else
		{
			cout <<"Succesfully logged in." << endl;
			system("PAUSE");
			cout << "\n\n" <<endl;
			main();				
		}
	}
	
	classcode = getCourseType();
	coursetime = getCourseTime();
	numparticipants = getNumParticipants();
	processRegistration (classcode, coursetime, numparticipants);
		
	cout <<endl<<"HAVE FUN COOKING!!!" <<endl;
		
	return 0;
}



bool loginInfo()
{
	string username, password, user, pass;

	cout << "Please enter your username:";
	cin >> username;
	cout << "Please enter your password:";
	cin >> password;

	ifstream read("file.txt");

	getline(read, user);
	getline(read, pass);

	if (username == user && password == pass)
	{
		return true;
	}
	else
	{
		return false;
	}
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
