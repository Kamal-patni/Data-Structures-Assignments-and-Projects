#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int val){
			data = val;
			next = NULL;
		}
};
class Singlylinkedlist
{
	private:
		node *Head,*tail;
	public:
		Singlylinkedlist()
		{
			Head = NULL;
			tail = NULL;
		}
		void menu();
		void AddNode(int);
		void AddToHead(int);
		void DelFromHead();
		void AddToTail(int);
		void DelFromTail();
		void Display();
		bool Search(int);
		void InsertAt(int,int);
		void DeleteAt(int);
};
void Singlylinkedlist :: AddNode(int a)
{
	node* temp=new node(a);
	temp->data=a;
	temp->next=NULL;
	if(Head==NULL)
	{
		Head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=tail->next;
	}
}
void Singlylinkedlist :: AddToHead(int item)
{
	node* temp = new node(item);
	temp->next = Head;
	Head = temp;
}
void Singlylinkedlist :: DelFromHead()
{
	node* temp = Head;
	Head = temp->next;
	delete temp;
}
void Singlylinkedlist :: AddToTail(int item)
{
	node* temp =  Head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node* n = new node(item);
	temp->next=n;
	n->next=NULL;
}
void Singlylinkedlist :: DelFromTail()
{
	node* temp =  Head;
	while((temp->next)->next !=NULL)
	{
		temp=temp->next;
	}
	temp->next = NULL;
}
void Singlylinkedlist :: Display()
{
	node* temp = Head;
	while(temp != NULL)
	{
		cout<<temp->data <<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
bool Singlylinkedlist :: Search(int ele)
{
	node* temp = Head;
	int count = 1;
	while(temp != NULL)
	{
		if(temp->data == ele)
		{return true;}
		temp = temp->next;
	}
	return false;
}
void Singlylinkedlist :: InsertAt(int pos,int val)
{
	node* newnode = new node(val);
	node* temp = Head;
	int count = 1;
	while(temp != NULL)
	{
		if((count+1) == pos)
		{
			node* temp2 = temp;
			newnode->next = (temp2->next);
			temp->next=newnode;
		}
		temp = temp->next;
		count+=1;
	}
}
void Singlylinkedlist :: DeleteAt(int pos)
{
	node* temp= Head;
	int count = 1;
	while(temp != NULL)
	{
		if((count+1)==pos)
		{
			node* temp2 = temp->next;
			temp->next=temp2->next;
			delete temp2;
		}
		temp = temp->next;
		count++;
	}
}
void Singlylinkedlist :: menu()
{
	cout<<endl<<"\t\tEnter your choice\t\t"<<endl;
	cout<<"\t1. Add to Head"<<endl;
	cout<<"\t2. Add to Tail"<<endl;
	cout<<"\t3. Delete from Head"<<endl;
	cout<<"\t4. Delete from Tail"<<endl;
	cout<<"\t5. Search in the Linked List"<<endl;
	cout<<"\t6. Insert in the Linked List"<<endl;
	cout<<"\t7. Delete in the Linked List"<<endl;
	cout<<"\t0. To Exit"<<endl;
}
int main()
{
	cout<<"\t\tProgram Started :"<<endl;
	cout<<"Enter the elements of the Linked List(enter 911 to stop) : "<<endl;
	Singlylinkedlist a;
	int elem,ch;
	while(elem != 911)
	{
		cin>>elem;
		if(elem!=911)
		{	a.AddNode(elem);}
	}
	cout<<endl<<"Entered Linked List : ";
	a.Display();
	a.menu();
	while(ch!=0)
	{
	cout<<endl<<"Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 0:
			break;
		case 1:
			int i;
			cout<<endl<<"Enter the element : ";
			cin>>i;
			a.AddToHead(i);
			break;
		case 2:
			int i2;
			cout<<endl<<"Enter the element : ";
			cin>>i2;
			a.AddToTail(i2);
			break;
		case 3:
			a.DelFromHead();
			break;
		case 4:
			a.DelFromTail();
			break;
		case 5:
			int i3;
			cout<<endl<<"Enter the element : ";
			cin>>i3;
			if(a.Search(i3))
				cout<<"Element is present in the Singly Linked List";
			else
				cout<<"Element is not present in the Singly Linked List";
			break;
		case 6:
			int i4,j;
			cout<<endl<<"Enter the position : ";
			cin>>i4;
			cout<<endl<<"Enter the element : ";
			cin>>j;
			a.InsertAt(i4,j);
			break;
		case 7:
			int i5;
			cout<<endl<<"Enter the position : ";
			cin>>i5;
			a.DeleteAt(i5);
			break;
		default:
			cout<<"Enter a valid choice";
	}
	if(ch!=0){
	cout<<endl<<"After Operations"<<endl;
	a.Display();
}}
}
