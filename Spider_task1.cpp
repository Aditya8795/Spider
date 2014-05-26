#include<iostream>
#include <cstdlib>
#include <stdlib.h> 
#include<ctype.h>
#include<limits.h>
#include<stdio.h>
//namespaces are used to avoid naming conflicts, so instead of using std::cout (ie standard namespace) inorder to use cout
//so this statement sets the default namespace as std, to avoid errors when we directly use cout.. etc
using namespace std;




class node{
	public:
		//the user data
       char name[20];
       int age;
       char occupation[20];
       char location[20];
       char gender;
       
       node *next; //pointer to the address of the next node
       
       
       };
       
       
       
       

		
		
		void add_user(node *head);
		void sort_users(node *head);
		void del_user(node *user);
		float median_age(node *head);
		float average_age(node *head);
		char* max_occupation(node *head);
		char* max_location(node *head);
		void suggest_friends(node *head,char *name);
		void segregate_age(node *head);
		void reverse(node *head);
		
		
	
void display(node *head){
	system("CLS");
	cout<<"displaying the list!!";
	
	node *temp;
	temp=head;
	int counter=1;
	
	if(head!=NULL){
		cout<<"linked list are:--\n";
	
	while(temp->next!=NULL){
		cout<<"Name No "<<counter<<":-"<<temp->name<<"\n";
		temp=temp->next;
	}
	cout<<"Last Name:-"<<temp->name<<endl;
	
	}
	system("pause>nul");
	counter++;
}

void add_user(node *head){
	system("CLS");
	
	//this a temporary node pointer
	node *temp;
	
	if(head==NULL){
		//now as head was pointing to NULL, we make it point to a new node(the HEAD NODE)
		head=new node;
		//and this new node is set to point to NULL as the list only has this one node right now
		head->next=NULL;
		
		//get the user data
		cout<<"Enter the new user's name : ";
		cin>>head->name;
		cout<<"Enter the new user's age : ";
		cin>>head->age;
		/* Tried a lot of stuff.. cant seem to easily make sure user enters only intergers
		if(!isdigit(temp1)){
			localhead->age=temp1;
			cout<<"done";
			system("pause>nul");
		}
		else{
			cin.clear();
			cin.ignore(1024,' ');
			cout<<"not done";
			system("pause>nul");
			return;
		}
		*/
		cout<<"Enter the new user's occupation : ";
		cin>>head->occupation;
		cout<<"Enter the new user's location : ";
		cin>>head->location;
		cout<<"Enter the new user's gender (M/F) : ";
		cin>>head->gender;
		if(head!=NULL){
			cout<<"head no longer null";
		}
	}
	else{
		//as the list HAS a head node, we set temp to point to the HEAD node
		temp=head;
		
		//and we use temp to jump along all the linked nodes to the last node in the list
		while(temp->next!=NULL){
			temp=temp->next;
		}
		
		//now we set the last node to point to the "empty" node which is to be appended to the last node
		temp->next= new node;
		
		//now that the last node is the just created node, set temp to point to it
		temp=temp->next;
		
		//get the user data
		cout<<"Enter the new user's name : ";
		cin>>temp->name;
		cout<<"Enter the new user's age : ";
		cin>>temp->age;
		cout<<"Enter the new user's occupation : ";
		cin>>temp->occupation;
		cout<<"Enter the new user's location : ";
		cin>>temp->location;
		cout<<"Enter the new user's gender (M/F) : ";
		cin>>temp->gender;
		
		//now that the node is the last one set its next as NULL
		temp->next=NULL;
		
		
	}
}

void sort_users(){
	
}

int main(){
	
	int choice=0;
	class node *head = NULL; //THE head (node pointer) is intialized and made to point to NULL
	
	while(1){
		
	
	cout<<"\n\n\n\n            WELCOME TO THE USER DATA MANAGEMENT MENU";
	cout<<"\n\n 1.Add a new user \n\n 2.Sort the existing users \n\n 3.Delete a existing user \n\n 4.Find the median age of all the users ";
	cout<<"\n\n 5.Find the average age of all the users \n\n 6.Find the occupation most users have \n\n 7.Find the locations most users live at ";
	cout<<"\n\n 8.Find users who could be friends of a particular user \n\n 9.Order the list using age of users \n\n 10.reverse the existing list \n\n";
	cout<<" Enter 0 to exit \n";
	
	cout<<"      enter the number corresponding to the choice to proceed \n";
	cin>>choice;
	
	switch(choice){
		
		case 1:add_user(head);
		break;
		
		case 2:
		break;
		
		case 0: exit(0);
		
	}
	
	display(head);
    } //while loop to infinity
    
	return 0;
}


       
