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
	
	int login,classcode, coursetime, numparticipants;
	string username, password, usern, passw; 

    
	
	cout<<"\tWELCOME TO ONE COOKING ACADEMY"<<endl<<endl<<endl;
	
	studentinfo = getInfo();
	classcode = getCourseType();
	coursetime = getCourseTime();
	numparticipants = getNumParticipants();
	processRegistration (classcode, coursetime, numparticipants);
		
	cout <<endl<< "HAVE FUN COOKING!!!" <<endl;
		
	return 0;
}

string getInfo()
{
    cout << "1 : Register \n2 :Login\nYour choice :" <<endl;
    cin >> login;
	
    if (login == 1)
    {
        string username, password;

        cout << "Enter your username :";
        cin >> username;
        cout << "Enter your password :";
        cin >> password;	
	
	ofstream file;
	file.open("data\\" + username + ".txt");
	
	file<<"username :"<<username<<endl<<"password :"<<password;
	file.close();
	
	main();
    }
	
	else if(choice==2)
    {
       bool status = loginfo();

       if(!status) 
       {
          cout<<"Invalid username or password!"<<endl;
          system("PAUSE");

	       return 0;
       }
       else
       {
           cout<<"Successfully Logged in"<<endl;
           system("pause");
           return 1;
       }
    } 
}

bool loginfo()
{
	cout << "Enter username :";
   	cin >> username;

   	cout << "Enter password :";
   	cin >> password;
	
    	
    	ifstream read("data\\" + username + ".txt");  
    	
    	getline(read, usern); 
    	getline(read, passw); 

    	

    	if (usern == username && passw == password)
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


