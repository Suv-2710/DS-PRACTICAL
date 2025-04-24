/*#include<iostream>
using namespace std;
int V, i, j, n;
class Student
{   
    public:
    int PRN, per;
    string name, add;
    int chain[100], key[100], loc[100];
    
        void table();
        void accept();
        void display();
        void search();
}h[100];

void Student :: table()
{
    for(i=0;i<n;i++)
    {
        chain[i]=-2;
        key[i]=-1;
    }

    cout<<"\n loc \t key \t chain";
    for(i=0;i<n;i++)
    {
            cout<<"\n"<< i <<"\t"<< key[i] <<"\t" << chain[i];
    }
    
}

void Student :: accept()
{   int loc, pos, prn , rno;
    string name;
    
    for (i=0;i<n;i++)
    {
        loc = key[i] % 10;
        pos = loc;
        do 
        {
            if(h[loc.prn]==-1)
            {
                h[loc].prn = key[i];
                cout<<"Enter Details";
                cin>> n[loc].rno >> n[loc].name >> n[loc].per;
                break;
            }
        }
    }
}

int main()
{
    Student s;
    s.table();
}*/





/*
Assignment 6
Def- a medical record system is a software application used to manage medical records including patient information medical history and 
treatment plan. Hash table can be used as a data structure to efficiently store and retrieve medical records.


#include<iostream>
using namespace std;
int key[20],n;

class medicalRecords{
    int ID;
    string Name;
    public:
    void Table();
    void display();
    void accept();
    void search();
    void modify();
}h[50];

void medicalRecords::Table(){
    cout<<"Enter No. of Records you want to store: ";
    cin>>n;
}

void medicalRecords::accept(){
    int loc;
    for(int i = 0; i<n; i++){
        cout<<"Enter ID "<<i<<" : ";
        cin>>key[i];
    }
    for (int i = 0; i<10;i++){
        h[i].ID = -1;
    }
    for (int i = 0; i<n; i++){
        loc = key[i]%10;
        if (h[loc].ID == -1){
            cout<<"Enter Name for ID "<<key[i]<<" : ";
            cin >> h[loc].Name;
            h[loc].ID = key[i];
            cout<<"Record Added at location "<<loc<<"."<<endl;
        }
        else{
            cout<<"\nCollision Occured at location "<<loc<<"!!!"<<endl;
            loc = (loc+1)%10;
            while (h[loc].ID != -1){
                loc = (loc+1)%10;
            }
            cout<<"Enter Name for ID "<<key[i]<<" : ";
            cin>>h[loc].Name;
            h[loc].ID = key[i];
            cout<<"Record Added at location "<<loc<<"."<<endl;
        }
    }
}

void medicalRecords::display(){
    cout <<"\nMedical Records: \n";
    cout<<"Location\tID\tName"<<endl;
    for (int i = 0; i<10;i++){
        cout<<i<<"\t\t"<<h[i].ID<<"\t"<<h[i].Name<<endl;
    }
}

void medicalRecords::search(){
    int id,ch;
    bool isFound = false;
    do
    {
        cout << "\nEnter patient ID to search: ";
        cin >> id;
        for (int i = 0; i < 10; i++) {
            if (h[i].ID == id) {
                isFound = true;
                cout << "\nRecord found at location " << i << ": ID = " << h[i].ID << ", Name = " << h[i].Name << endl;
                break;
            }
        }
        if (!isFound) {
            cout << "Record not found!" << endl;
        }
        cout << "\nDo you want to search another record? (Yes-1/No-0): ";
        cin >> ch;
    } while (ch!=0);
}

void medicalRecords::modify(){
    int id,ch;
    bool isFound = false;
    do
    {
        cout << "\nEnter patient ID to modify: ";
        cin >> id;
        for (int i = 0; i < 10; i++) {
            if (h[i].ID == id) {
                isFound = true;
                cout << "\nRecord found at location " << i << ": ID = " << h[i].ID << ", Name = " << h[i].Name << endl;
                cout << "\nEnter new Name for ID " << id << ": ";
                cin >> h[i].Name;
                cout << "Record modified successfully!" << endl;
                break;
            }
        }
        if (!isFound) {
            cout << "Record not found!" << endl;
        }

        cout << "\nDo you want to modify another record? (Yes - 1 / No - 0): ";
        cin >> ch;
    } while (ch != 0);
}

int main(){
    int choice;
    cout << "\n\tMedical Record System\n";
    medicalRecords m;
    m.Table();
    do
    {
        cout << "\n1. Add Medical Records\n2. Display Medical Records\n3. Search Medical Records\n4. Modify Medical Records\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                m.accept();
                break;
            case 2:
                m.display();
                break;
            case 3:
                m.search();
                break;
            case 4:
                m.modify();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    cout << "\nDo you want to continue? (Yes-1/No-0): ";
        cin >> choice;
    } while (choice != 0);
    return 0;
}
    */