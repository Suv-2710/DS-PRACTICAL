#include<iostream>
using namespace std;

class RRS
{
    string name, address, adhar;
    int price;
    RRS *LC, *RC;

public:
    void create();
    void insert(RRS *root, RRS *next);
    void display(RRS *root);
    void search( RRS *root);
} *root = NULL, *st[10];

void RRS::create()
{
    int ch;
    RRS *next;
  
    if (root == NULL) 
    {
        root = new RRS;
        cout << "Enter the Passenger's information" ;
        cin >> root->name >> root->address >> root->adhar >> root->price;
        root->LC = root->RC = NULL;
    }

    do {
        cout << "Do you want to add more data: ";
        cin >> ch;
        if (ch == 1)
        {
            next = new RRS;
            cout << "Enter new information: ";
            cin >> next->name >> next->address >> next->adhar >> next->price;
            next->LC = next->RC = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}

void RRS::insert(RRS *root, RRS *next) {
    if (next->price < root->price)
    {
       
        if (root->LC == NULL) 
        {
            root->LC = next;
        } 
        else
        {
            insert(root->LC, next);
        }
    } 
    else 
    {
       
        if (root->RC == NULL) 
        {
            root->RC = next;
        } 
        else
        {
            insert(root->RC, next);
        }
    }
}

void RRS::display(RRS *root) 
{
    if (root == NULL)
    return;
    display(root->LC);  
    display(root->RC);  
    cout << "\n" << root->name << "\t" << root->address << "\t" << root->adhar << "\t" << root->price;
    
}

void RRS :: search( RRS *root)
{	int f=0;
	int pz;
	cout<< "Enter the price of ticket:";
	cin>>pz;
	if(pz > root->price)
		{
		if(pz== root->price)
		{
		cout<<"Record found";
		f=1;
		}
		root=root->RC;
		}
	else
		{
		if(pz  == root->price)
		{
		cout<<"Record found";
		f=1;
		}
		root=root->LC;
		}
}

int main() {
    RRS r;
    int choice, i;
    do {
        cout << "\nRailway Reservation System" ;
        cout << "\n1. Create\n2. Display\n3. Search\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:r.create();
                        break;
            case 2: cout << "\n Name \t Address \t Adhar \t Price" ;
                         r.display(root);  
                        break;
            case 3 : r.search( root);
                        break;
        }
        cout << "\nDo you want to continue";
        cin >> i;
    } while (i == 1);
    return 0;
}

