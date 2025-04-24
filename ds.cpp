#include<iostream>
using namespace std;

class employee
{
public :
int id, salary;
string name, position;
employee *next; 
void accept();
void display();
}*start = NULL;

void employee :: accept()
{ 
employee *newnode, *next;
cout<<"Enter id , name , salary and position of employee ";
cin>>newnode->id>> newnode->name>>newnode->salary>>newnode->position;
newnode->next=NULL;
if(start == NULL)

start= newnode;
else
{
employee *temp;
temp= start ;
while(temp->next!= NULL)
{
temp=temp->next;
}
temp->next =newnode;
}
}

void employee :: display()
{
if (start == NULL) 
{
        cout << "No employees to display." ;
 }
    employee *temp ;
    temp = start;
  while (temp != NULL) {
 cout << "id " << temp->id << ", name: " << temp->name << ", salary: " << temp->salary << ", position: " << temp->position ;
 temp = temp->next;
 }
}

int main()
{
    employee e;  
    e.accept();  
    e.display(); 
 return 0;
}

