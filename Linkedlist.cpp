#include <iostream>
using namespace std;
#include <windows.h>

class node
{
	public:
		int data;
		node* next;
};
class linkedlist
{
	private:
		node* first;
	public:
		//*********************************************************************************************1
		linkedlist()
		{
			first = NULL;
		}
		//*********************************************************************************************2
		void treverse()
		{
			if (first == NULL)
				cout << "Linked List is Empty.";
			else
			{
				node * temp = first;
				cout << "My Linked List : ";
				while(temp)
				{
					cout << temp->data << " ";
					temp = temp->next;
				}
			}
			cout << "\n\n";
		}
		//*********************************************************************************************3
		bool insertBeg(int Data)
		{
			node* newnode = new node;
			newnode->data = Data;
			newnode->next = first;
			first = newnode;
			return 1;
		}
		//*********************************************************************************************4
		bool insertlast(int Data)
		{
			node*temp = first;
			if(!first)
				return insertBeg(Data);
			else
			{
				while(temp->next)
					temp = temp->next;
				node*end = new node;
				end->data = Data;
				temp->next = end;
				end->next = NULL;
				return 1;
			}
			return 0;
		}
		//*********************************************************************************************5
		bool insert(int Data,int key)
		{
			node* temp = first;
			if(first == NULL)
				return insertBeg(Data);
			if(first->next == NULL && first->data==key)
				return insertlast(Data);		
			else
			{
				temp = Find(key);
				if(temp)
				{
					node* newnode = new node;
				newnode->data = Data;
				newnode->next = temp->next;
				temp->next = newnode;
				return 1;
				}
				return 0;
		}
			return 0;
		}
		//*********************************************************************************************6
		node* Find(int Data)
		{
			if (first == NULL)
			{
				return NULL;				
			}
			else
			{
				node * temp = first;
				while(temp->next)
				{
					temp = temp->next;
					if(temp->data == Data)
						return temp;
				}				
			}
			return NULL;
		}
		//*********************************************************************************************7
		bool DeleteBeg()
		{
			if(first)
			{
				node* temp = first;
				first = first->next;
				delete temp;
				return 1;			
			}
			return 0;
		}
		//*********************************************************************************************8
		bool Deletelast()
		{
			node* temp = first;
			if(first)
			{
				while(temp->next->next)
				{
					temp= temp->next;
				}
				node* temp2;
				temp2 = temp->next;
				temp->next = NULL;
				delete temp2;
				return 1;
			}
			return 0;
				
		}
		//*********************************************************************************************9
		bool Delete(int Data)
		{
			if(first == 0)
				return 0;
			if(first->next == 0 and first->data == Data)
				return DeleteBeg();
			else
			{
				node* temp = first;
				node* temp2;
				while(temp->next->data!=Data)
					temp = temp->next;
				temp2 = temp->next;
				temp->next=temp2->next;
				delete temp2;				
				return 1;
			}
				return 0;
		}
		//*********************************************************************************************9
		bool Empty()
		{
			node*temp = first;
			while(first)
			{
				temp = first;
				first = first->next;
				delete temp;
			}
		}
};

int main (void)
{
	node b;
	linkedlist a;
	int num=-1,Data,key;
	cout << "*********************************" << endl ;
	cout << "**** WELCOME TO LINKED LIST *****" << endl ;
	while(num)
	{
		cout << "*********************************" << endl ;
		cout << "************ MAIN MENU **********" << endl ;
		cout << "Press 0 to 'EXIT'." << endl;
		cout << "Press 1 for 'Insert Begining'." << endl;
		cout << "Press 2 for 'Insert Last'." << endl;
		cout << "Press 3 for 'Insert Anywhere'." << endl;
		cout << "Press 4 for 'Find Element'." << endl;
		cout << "Press 5 for 'See YOUR Linked List'." << endl;
		cout << "Press 6 for 'Delete First'." << endl;
		cout << "Press 7 for 'Delete End'." << endl;
		cout << "Press 8 for 'Delete Anywhere'." << endl;
		cout << "Press 9 for 'Empty Linked List'." << endl;
		cout << "*********************************" << endl ;
		cout << "Enter you desired input number : " ;	

		cin >> num;
		if (num == 0)
			return 0;
		if (num == 1)
			{				
				cout << "Enter number to insert : ";
				cin >> Data;
				if (a.insertBeg(Data))
					cout << "\n\nInserted!\n";
				else
					cout << "\n\nNot Inserted!\n";
				a.treverse();
			}
		if (num == 2)
			{
				cout << "Enter number to insert : " ;
				cin >> Data;
				if (a.insertlast(Data))
					cout << "\n\nInserted!\n";
				else
					cout << "\n\nNot Inserted!\n";
				a.treverse();
			}
		if (num == 3)
			{
				cout << "Enter number to insert : ";
				cin >> Data;
				cout << "Enter you Key to place after : ";	
				cin >> key;
				if (a.insert(Data,key))
					cout << "\n\nInserted!\n";
				else
					cout << "\n\nNot Inserted!\n";
				a.treverse();
			}
		if (num == 4)
			{
				cout << "Enter number to Find : ";
				cin >> Data;
				node* f = a.Find(Data);
				if (f)
					cout << "Finding element : " << f->data;
				else
					cout << "Not found " << endl;
				a.treverse();
			}
		if (num == 5)
			a.treverse();			
		if (num == 6)
			{
				if (a.DeleteBeg())
					cout << "\n\nBegining Deleted!\n";
				else
					cout << "\n\nBegining Not Deleted!\n";
				a.treverse();				
			}
		if (num == 7)
			{	
				if (a.Deletelast())
					cout << "\n\nEnd Deleted!\n";
				else
					cout << "\n\nEnd Not Deleted!\n";
				a.treverse();
			}
		if (num == 8)
			{
				cout << "Enter number to Delete : ";
				cin >> Data;
				if (a.Delete(Data))
					cout << "\n\nEverywhere Deleted!\n";
				else
					cout << "\n\nEverywhere Not Deleted!\n";
				a.treverse();	
			}
		if (num == 9)
			{
			a.Empty();
			a.treverse();				
			}
	}
}
