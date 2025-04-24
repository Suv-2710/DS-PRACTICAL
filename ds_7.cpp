#include<iostream>
using namespace std;
int key[10],c[10],n,i,loc,pos;
class student
{ 
  int rollno,per,prn;
  string name;
  public:
  void table();
  void display();
  void accept();
  void search();
  void modify();
  void addrecord();
}h[100];

void student::table()
{
 cout<<"enter the no. of records";
 cin>>n;
 cout<<"\n  enter the elements for key array:";
 for(i=0;i<n;i++)
 { 
  cin>>key[i];
  }
 
 for(i=0;i<10;i++)
 {
   h[i].prn=-1;
   c[i]=-2;
  }
  
 }
 
void student::display()
{
  cout<<"\nLOC\tPRN\tROLLNO\tNAME\tCHAIN";
  cout<<"\n";
  
  for(i=0;i<10;i++)
  { 
    cout<<i<<"\t"<<h[i].prn<<"\t"<<h[i].rollno<<"\t"<<h[i].name<<"\t"<<c[i]<<"\n";
  }
 }
 
void student::accept()
{
int x;
cout<<"\n N="<<n;
 for(i=0;i<n;i++)
 {
  loc=key[i]%10;
  pos=loc;
  do{
   if(h[loc].prn==-1)
   {
    h[loc].prn=key[i];
    cout<<"\n Enter the details";
    cout<<"\nRollno:";
    cin>>h[loc].rollno;
    cout<<"\nName:";
    cin>>h[loc].name;
    cout<<"\nPercentage:";
    cin>>h[loc].per;
    break;
    }
   else{
   loc++;
   c[pos]=loc;
   if(loc>9)
   loc=0;
  /* */
   }}while(loc<10);
  }
 }

void student::search()
{
int prnn;
cout<<"\n Enter the prn no of student which is to be searched:";
cin>>prnn;
loc=prnn%10;
for(i=0;i<10;i++)
{
if(h[loc].prn==prnn)
{
 cout<<"\n record found";
 break;
} 
/*else
{
 cout<<"not found";
 break;
 }*/else
      loc++;
}
}

void student::modify()
{
int prnn;
cout<<"\n Enter the prn no of student which is to be modified";
cin>>prnn;
loc=prnn%10;
for(i=0;i<10;i++)
{
if(h[loc].prn==prnn)
{
 cout<<"\nenter the new details rollno ,name,per";
 cin>>h[loc].rollno>>h[loc].name>>h[loc].per;
 break;
} 
else
{
 loc++;
 }
}
}

void student::addrecord()
{
int x,keynew;
cout<<"\n N="<<n;
cout<<"\n Enter the PRN";
cin>>keynew;
 
  loc=keynew%10;
  pos=loc;
  do{
   if(h[loc].prn==-1)
   {
    h[loc].prn=key[i];
    cout<<"\n Enter the details";
    cout<<"\nRollno:";
    cin>>h[loc].rollno;
    cout<<"\nName:";
    cin>>h[loc].name;
    cout<<"\nPercentage:";
    cin>>h[loc].per;
    break;
    }
   else{
   loc++;
   c[pos]=loc;
   if(loc>9)
   loc=0;
   }
    }while(loc<10);
  
 }


int main()
{
student h;
int ch;
do{
cout<<"\n1.Empty table\n2.Accept the student details\n3.Display the hash table\n4.Search\n5.Modify\n6.Add new Record\n7.Exit";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch){
    case 1:h.table();
           break;
    case 2:h.accept();
           break;
    case 3:h.display();
           break;
    case 4:h.search();
           break;
    case 5:h.modify();
           break;
    case 6:h.addrecord();
           break;
    case 7:exit(0);
}
}while(ch!=7);

 return 0;
}


































/* if(c[loc]!=-2)
   {
   x=c[pos];
   c[x]=loc;
      }
   else{
   c[pos]=loc;
   }*/