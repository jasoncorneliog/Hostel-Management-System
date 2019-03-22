#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;
    FILE *fp, *ft;
    char another, choice;
    char xusn[20];
    long int recsize;
struct student {
    char fname[20],mname[20],lname[20],usn[20],branch[20],facility[10];
    char flat_no[5],building_name[20],area_name[20],pincode[10],city[20],state[20];
    char room_no[10],floor_no[5],rent[10],attendance[3],stud_attendance[3],initial_deposit[10],current_balance[10];

        char course[100];
        int section;
    };struct student e;

class hostel
{
	public:
	void put_data()
	{
		 fseek(fp,0,SEEK_END);
            another ='Y';
            while((another == 'Y')||(another == 'y'))
            {
                  system("cls");
                cout<<"Enter the First Name : ";
                cin>>e.fname;
				cout<<endl<<"Enter the Last Name : ";
                cin>>e.lname;
                cout<<endl<<"Enter the Middle Name  : ";
                cin>>e.mname;
                cout<<endl<<"Enter address details :  ";
                cout<<endl<<"Enter flat number without spaces: ";
                cin>>e.flat_no;
                cout<<endl<<"Enter building name without spaces: ";
			    cin>>e.building_name;
			    cout<<endl<<"Enter area name without spaces: ";
			    cin>>e.area_name;
			    cout<<endl<<"Enter city without spaces: ";
			    cin>>e.city;
			    cout<<endl<<"Enter state: ";
			    cin>>e.state;
		        cout<<endl<<"Enter pincode: ";
			    cin>>e.pincode;
                cout<<endl<<"Enter usn no: ";
                cin>>e.usn;
			    cout<<endl<<"Enter branch name: ";
			    cin>>e.branch;
			    cout<<endl<<"Enter assigned room number: ";
			    cin>>e.room_no;
			    cout<<endl<<"Enter corresponding floor number: ";
			    cin>>e.floor_no;
			    cout<<endl<<"Enter rent per month: ";
			    cin>>e.rent;
                cout<<endl<<"Enter initial rent deposit of student: ";
                cin>>e.initial_deposit;
                cout<<endl<<"Enter type of room facilities(Furnished/NonFurnished): ";
                cin>>e.facility;
                cout<<"Enter total attendance taken: ";
				cin>>e.attendance;
				cout<<endl<<"Enter attendance of the student: ";
				cin>>e.stud_attendance;
				cout<<"Enter current balance: ";
				cin>>e.current_balance;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
	}

void show_data()
{
	system("cls");
           rewind(fp);
           cout << "=== View the Records in the Database ===";
           cout << "\n";
           while (fread(&e,recsize,1,fp) == 1){
           cout << "\n";
           cout <<"\nName     :: " <<e.fname<<" "<<e.lname;
           //cout << "\n";
           cout <<"\nAddress  :: " <<e.flat_no<<" "<<e.building_name<<" "<<e.area_name<<" "<<e.city<<" "<<e.state<<" "<<e.pincode;
           cout <<"\nUsn  :: "<<e.usn;
           cout<<"\nBranch ::"<<e.branch;
           cout<<"\nRoom no:: "<<e.room_no;
           cout<<"\nFloor no:: "<<e.floor_no;
           cout<<"\nRent ::"<<e.rent;
           cout<<"\nTotal attendance taken: "<<e.attendance;
		   cout<<endl<<"Attendance of the student: "<<e.stud_attendance;
           cout<<endl<<"Current balance: "<<e.current_balance;
		   cout<<endl<<"Initial deposit: "<<e.initial_deposit;
		   cout<<endl<<"Facility type: "<<e.facility;
           }
           cout << "\n\n";
           system("pause");
}

void delete_data()
{
	system("cls");
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the usn of the student to delete : ";
              cin >> xusn;

              ft = fopen("temp.txt", "wb");

              rewind(fp);
              while (fread (&e, recsize,1,fp) == 1)

                 if (strcmp(e.usn,xusn) != 0)
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.txt","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
              }
}

void modify_data()
{
	system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the usn of the student : ";
              cin >> xusn;

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (strcmp(e.usn,xusn) == 0)
                {
                cout<<"Enter the First Name : ";
                cin>>e.fname;
				cout<<endl<<"Enter the Last Name : ";
                cin>>e.lname;
                cout<<endl<<"Enter the Middle Name  : ";
                cin>>e.mname;
                cout<<endl<<"Enter address details :  ";
                cout<<endl<<"Enter flat number without spaces: ";
                cin>>e.flat_no;
                cout<<endl<<"Enter building name without spaces: ";
			    cin>>e.building_name;
			    cout<<endl<<"Enter area name without spaces: ";
			    cin>>e.area_name;
			    cout<<endl<<"Enter city without spaces: ";
			    cin>>e.city;
			    cout<<endl<<"Enter state: ";
			    cin>>e.state;
		        cout<<endl<<"Enter pincode: ";
			    cin>>e.pincode;
                cout<<endl<<"Enter usn no: ";
                cin>>e.usn;
			    cout<<endl<<"Enter branch name: ";
			    cin>>e.branch;
			    cout<<endl<<"Enter room number: ";
			    cin>>e.room_no;
			    cout<<endl<<"Enter floor number: ";
			    cin>>e.floor_no;
			    cout<<endl<<"Enter rent: ";
			    cin>>e.rent;
				cout<<endl<<"Enter type of room facilities(Furnished/NonFurnished): ";
                cin>>e.facility;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
				}

            }
            if (strcmp(e.usn,xusn) != 0)
            {

                cout<<"Record not found"; }
            cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
}

	   void update_attendance()
	   {
	   	system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the usn of the student : ";
              cin >> xusn;

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (strcmp(e.usn,xusn) == 0)
                {
                cout<<"Enter total attendance taken: ";
				cin>>e.attendance;
				cout<<endl<<"Enter attendance of the student: ";
				cin>>e.stud_attendance;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }

            }
              if (strcmp(e.usn,xusn) != 0)
            {
                cout<<"Record not found"; }
            cout << "\n Modify Attendance of Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
	   }

	void update_rent()
	{
          system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout<< "\n Enter the usn of the student : ";
              cin>>xusn;
            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (strcmp(e.usn,xusn) == 0)
                {
                cout<<"Enter current balance: ";
				cin>>e.current_balance;
				cout<<"Enter new initial deposit value: ";
				cin>>e.initial_deposit;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }
            }
              if (strcmp(e.usn,xusn) != 0)
            {
            cout<<"Record not found"; }
            cout << "\n Modify Attendance of Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
	}
};

int main()
{
hostel h;
fp=fopen("users.txt","rb+");
      if(fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }
recsize = sizeof(e);
 for(;;)
 {
 	system("cls");
     cout << "\t\t====== HOSTEL STUDENT INFORMATION SYSTEM ======";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t======================";
     cout << "\n \t\t\t  1. Add Student Records";
     cout << "\n \t\t\t  2. List Student Records";
     cout << "\n \t\t\t  3. Modify Student Records";
     cout << "\n \t\t\t  4. Delete Student Records";
     cout << "\n \t\t\t  5. Update Attendance";
     cout << "\n \t\t\t  6. Update Rent";
     cout << "\n \t\t\t  7. Exit   Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     fflush(stdin);
     choice = getche();
     switch(choice)
 	{
 		case '1':h.put_data();
 		         break;
 		case '2':h.show_data();
		         break;
		case '3':h.modify_data();
		         break;
		case '4':h.delete_data();
		         break;
		case '5':h.update_attendance();
		         break;
		case '6':h.update_rent();
		         break;
		case '7':exit(0);
 	}
 }
}