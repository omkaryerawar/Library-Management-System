//Library Management System in Data Structure

#include<iostream>
#include<conio.h>
using namespace std;

class library
{
	private:
		struct Node
		{
			int id;
			string name,author,publisher;
			Node *next;               //it will point towards next address
		};
	
	public:
		Node *head=NULL;
		void menu();
		void insert();
		void search();
		void update();
		void del();
		void sort();            //because we want to show all records in a proper order(i.e. increasing) w.r.t. to their IDs.
		void show();
		
	
	
};

//Home Page

void library::menu()                                                      //we have created a basic menu here
{
	p:
		system("cls");
		int choice;
		cout<<"\n\n\t\t***********************************************";
		cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
		cout<<"\n\n\t\t***********************************************";
		cout<<"\n\n 1. Insert New Record";
		cout<<"\n\n 2. Search Record";
		cout<<"\n\n 3. Update Record";
		cout<<"\n\n 4. Delete Record";
		cout<<"\n\n 5. Show all Record";
		cout<<"\n\n 6. Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				search();
				break;
			
			case 3:
				update();
				break;
			case 4:
				del();
				break;
			case 5:
				sort();
				show();
				break;
			case 6:
				exit(0);
			default:
				cout<<"\n\n Invalid Choice..Please Try Again..";
		}
		getch();              //we are using this instead of 'return' beacuse it won't terminate the code like return does.
		goto p;               //After pressing enter it will come back to home page
		
}

//Insertion of book records

void library::insert()
{
	system("cls");
	cout<<"\n\n\t\t***********************************************";
	cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
	cout<<"\n\n\t\t***********************************************";
	Node *new_node= new Node;
	
	
	cout<<"\n\n Book ID : ";
	cin>>new_node->id;
	cout<<"\n\n Name : ";
	cin>>new_node->name;
	cout<<"\n\n Author Name : ";
	cin>>new_node->author;
	cout<<"\n\n Publisher Name : ";
	cin>>new_node->publisher;
	
	new_node ->next =NULL;                       //we have connected that new node to NULL since we are assuming it as a first node
	
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		Node *temp=head;
		while(temp->next !=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=new_node;
	}
	
	cout<<"\n\n\t\t New Book Inserted Successfully.....";
		
	
}

//Searching a book record

void library::search()
{
		system("cls");
		int test_id,found=0;
		cout<<"\n\n\t\t***********************************************";
		cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
		cout<<"\n\n\t\t***********************************************";
		if(head==NULL)                                                         //if our linked list is empty
		{
			cout<<"\n\n Nothing is there to show now...";
		}
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>test_id;
			Node *temp=head;
			while(temp !=NULL)
			{
				if(test_id==temp->id)
				{
					system("cls");
	                cout<<"\n\n\t\t***********************************************";
	                cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
	                cout<<"\n\n\t\t***********************************************";
	                cout<<"\n\n Book ID : "<<temp->id;
	                cout<<"\n\n Book Name : "<<temp->name;
	                cout<<"\n\n Author Name : "<<temp->author;
	                cout<<"\n\n Publisher Name : "<<temp->publisher;
	                found++;
					
				}
				
				temp=temp->next;
			}
			
			if(found==0)
			{
				cout<<"\n\n Book ID is Invalid...";
			}
				
		}	
}

//Updating a book record

void library::update()
{
	    system("cls");
		int test_id,found=0;
		cout<<"\n\n\t\t***********************************************";
		cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
		cout<<"\n\n\t\t***********************************************";
		if(head==NULL)                                                         //if our linked list is empty
		{
			cout<<"\n\n Nothing is there to show now...";
		}
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>test_id;
			Node *temp=head;
			while(temp !=NULL)
			{
				if(test_id==temp->id)
				{
					system("cls");
	                cout<<"\n\n\t\t***********************************************";
	                cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
	                cout<<"\n\n\t\t***********************************************";
	                cout<<"\n\n Book ID : ";
					cin>>temp->id;
	                cout<<"\n\n Book Name : ";
					cin>>temp->name;
	                cout<<"\n\n Author Name : ";
					cin>>temp->author;
	                cout<<"\n\n Publisher Name : ";
					cin>>temp->publisher;
	                found++;
	                
	                cout<<"\n\n\t\t Updated the Book Record Successfully";
					
				}
				
				temp=temp->next;
			}
			
			if(found==0)
			{
				cout<<"\n\n Book ID is Invalid...";
			}
				
		}
	
}

//Deleting a specific book record

void library::del()
{
	system("cls");
		int test_id,found=0;
		cout<<"\n\n\t\t***********************************************";
		cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
		cout<<"\n\n\t\t***********************************************";
		if(head==NULL)                                                         //if our linked list is empty
		{
			cout<<"\n\n Nothing is there to show now...";
		}
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>test_id;
		    
			if(test_id==head->id)                     //deletion at head
			{
			   Node *temp=head;
			   head=head->next;
			   delete temp;
			   cout<<"\n\n Deleted the Book Record Successfully.....";
			   found++;	
			}
			else
			{
				Node *pre=head;         //previous node 
				Node *ptr=head;         //current node
				
				while(ptr !=NULL)
				{
					if(test_id==ptr->id)
					{
						pre->next =ptr->next;
						delete ptr;
						cout<<"\n\n Deleted the Book Record Successfully.....";
						found++;
						break;
					}
					
					pre=ptr;
					ptr=ptr->next;
					
				}
				
			}
			
		    if(found==0)
			{
				cout<<"\n\n Book ID is Invalid...";
			}	
		}
	
}

//Sorting book records according to their IDs

void library::sort()                        
{
	
	if(head==NULL)                                                         
	{       
	        system("cls");
	        cout<<"\n\n\t\t***********************************************";
		    cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
		    cout<<"\n\n\t\t***********************************************";
			cout<<"\n\n Nothing is there to show now...";
			getch();
			menu();
	}
	
	int count=0;           //it will count number of records present
	int test_id;
	string test_name,test_author,test_publisher;
	
	Node *temp=head;
	while(temp !=NULL)
	{
		count++;
		temp=temp->next;
	}
	
	for(int i=1;i<=count;i++)
	{
		Node *temp=head;
		
		for(int j=1;j<count;j++)
		{
			if(temp->id > temp->next->id)
			{   
			    //save data in temporary variables
				test_id=temp->id;
				test_name=temp->name;
				test_author=temp->author;
				test_publisher=temp->publisher;                     //trying to swap it & storing it in temporary variables
				
				//save data in current node
				temp->id=temp->next->id;
				temp->name=temp->next->name;
				temp->author=temp->next->author;
				temp->publisher=temp->next->publisher;
				
				//save data in next node
				
				temp->next->id=test_id;
				temp->next->name=test_name;
				temp->next->author=test_author;
				temp->next->publisher=test_publisher;	 
			}
			
			temp= temp->next;
		}
	}	
}

//Showing all the Book records present in the library management system

void library::show()
{
	    system("cls");
		cout<<"\n\n\t\t***********************************************";
		cout<<"\n\n\t\t****** LIBRARY MANAGEMENT SYSTEM **************";
		cout<<"\n\n\t\t***********************************************";
		
			Node *temp=head;
			while(temp !=NULL)
			{
				
	            cout<<"\n\n Book ID : "<<temp->id;
	            cout<<"\n\n Book Name : "<<temp->name;
	            cout<<"\n\n Author Name : "<<temp->author;
	            cout<<"\n\n Publisher Name : "<<temp->publisher;
				cout<<"\n\n ***************************************";				
				temp=temp->next;
			}
				
}




int main()
{
	library obj;
	obj.menu();
	
	return 0;
}
