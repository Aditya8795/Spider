#include<iostream>
#include <cstdlib>
#include <stdlib.h> 
#include<ctype.h>
#include<limits.h>
#include<stdio.h>
#include<string.h>
//namespaces are used to avoid naming conflicts, so instead of using std::cout (ie standard namespace) inorder to use cout
//so this statement sets the default namespace as std, to avoid errors when we directly use cout.. etc
using namespace std;




class node
{
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
		
		
	
void display(node *(*head))
{
	system("CLS");
	
	node *temp;
	temp=*(head);
	int counter=1;
	
	//traverse along the linked list
	if(temp!=NULL)
	{
		cout<<"	Linked List is now:--\n";
	
	    while(temp->next!=NULL){
	    	
		    cout<<"Name No "<<counter<<":-"<<temp->name<<"\n";
		    temp=temp->next;
		    counter++; // keeps track of the nth node (the no)
	    }
	    
	cout<<"Name No "<<counter<<":-"<<temp->name<<endl;
	
	}
	else
	{
		//if the List is Empty
		cout<<"\n\nNothing to display - As list is Empty\n";
	}
	
	system("pause>nul");
	
}

// the recived arguments are 2 pointers both to the nodes that are to be swapped - a mutator, changes the original list
void swap(node *node1, node *node2)
{
	//temp storage of info while swapping takes place
	node temp;
	//swap individual data attributes
	strcpy(temp.name, node1->name);
	strcpy(node1->name,node2->name);
	strcpy(node2->name,temp.name);
	
	temp.age=node1->age;
	node1->age=node2->age;
	node2->age=temp.age;
	
	strcpy(temp.occupation, node1->occupation);
	strcpy(node1->occupation,node2->occupation);
	strcpy(node2->occupation,temp.occupation);
	
	strcpy(temp.location, node1->location);
	strcpy(node1->location,node2->location);
	strcpy(node2->location,temp.location);
	
	temp.gender=node1->gender;
	node1->gender=node2->gender;
	node2->gender=temp.gender;
	
	// nodes swapped!
}

node* search(char *username, node *localhead)
{
	system("CLS");
	node *temp;
	temp=localhead;
	//NOW I AM PASSING THE POINTER TO GUY BEFORE THE USER TO BE DELETED, UNLESS THE USER IS POINTED TO BE HEAD THEN ITS THE USER ITSEF- this is crazy!!
	//check if list is empty
	if(temp!=NULL)
	{
			//the first guy wont be considered, it starts from 2nd user 
		if((strcmp(temp->name,username)==0))
		{
			return(temp);
		}
		
		while(temp->next!=NULL)
		{	
		if((strcmp((temp->next)->name,username)==0))
			{
				//when found send the pointer to the user to the del_user()
				return(temp);
			}
			
			//move along the list
			temp=temp->next;
			
		}
		
	}
	else
	{
		cout<<"\n\nThis is a empty list! No Entry available for deletion! \n";
		system("pause>nul");
		return(NULL);
		
	}
	
	//if the whole list has been searched and this user hasnt been found and the list isnt empty then this =>
	cout<<"\n\nNo entry with such a name was found, please check your spelling\n";
	system("pause>nul");
	return(NULL);
	/*ORIGINAL METHOD TO FIND THE USER TO BE DELETED, above i will try to get the guy before the user
	//check if list is empty
	if(temp!=NULL)
	{
		
		do
		{
			if((strcmp(temp->name,username)==0))
			{
				//when found send the pointer to the user to the del_user()
				return(temp);
			}
			//move along the list
			temp=temp->next;
		}while(temp->next!=NULL);
		
		//the last guy is pointing to NULL, just in case this user is at the end..
		if((strcmp(temp->name,username)==0))
			{
				return(temp);
			}
	}
	else
	{
		cout<<"\n\nThis is a empty list! No Entry available for deletion! \n";
		system("pause>nul");
		return(NULL);
		
	}
	
	//if the whole list has been searched and this user hasnt been found and the list isnt empty then this =>
	cout<<"\n\nNo entry with such a name was found, please check your spelling\n";
	system("pause>nul");
	return(NULL);
	*/
	
}
//- a mutator, changes the original list
void add_user(node **head){
	system("CLS");
	
	//this a temporary node pointer
	node *temp;
	
	if(*head==NULL){
		//now as head was pointing to NULL, we make it point to a new node(the HEAD NODE)
		*head=new node;
		//and this new node is set to point to NULL as the list only has this one node right now
		(*head)->next=NULL;
		
		//get the user data
		cout<<"Enter the new user's name : ";
		cin>>(*head)->name;
		cout<<"Enter the new user's age : ";
		cin>>(*head)->age;
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
		cin>>(*head)->occupation;
		cout<<"Enter the new user's location : ";
		cin>>(*head)->location;
		cout<<"Enter the new user's gender (M/F) : ";
		cin>>(*head)->gender;
	}
	else{
		//as the list HAS a head node, we set temp to point to the HEAD node
		temp=*head;
		
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

//I am going to implement BUBBLE SORT - a mutator, changes the original list
void sort_users(node **head){
	system("CLS");
		
	int swapped;
	
	//this a temporary node pointer - used to traverse the linked list
	node *temp;
	
	//this ptr is used to limit the itrative round as part of the linked list gets sorted, it keeps the sorting to the unsorted part
	node *ptr;
	ptr=NULL;
	
	//check if its a Empty List
	if(*head==NULL)
	{
		cout<<"\n\n\n This is a Empty List, Nothing to SORT.\n\n";
		system("pause>nul");
		return;
	}
	else
	{
		do
		{
			swapped=0; //so the loop will exit unless 2 nodes are swapped in this itrative round (ie swapped is set to a non-zero value)
			temp=*head;
			
			//start of itrative round
			while(temp->next!=ptr)
			{
				if((strcmp(temp->name,(temp->next)->name))>0)
				{
					swap(temp,temp->next);
					swapped=1;
				}
				//check pairwise and move on along the list
				temp=temp->next;
			}
			//once the nth round is completed those n sorted elements (from the end) are not to be checked anymore (a waste of time)
			ptr=temp;
			
			
		}while(swapped);
	}
	
	
	
}

//- a mutator, changes the original list
void del_user(node *user)
{
	node *temp;

	system("CLS");
		
	if(user==NULL)
	{
		//this means either empty list OR no such user found
		return;
	}
	
	temp=user;
	
	
	cout<<"\n\n"<<(user)->name<<" has been deleted \n";
	system("pause>nul");
}


int main(){
	
	int choice=0;
	class node *head = NULL; //THE head (node pointer) is intialized and made to point to NULL
	char name_user[20];
	while(1){
		
	
	cout<<"\n\n\n\n            WELCOME TO THE USER DATA MANAGEMENT MENU";
	cout<<"\n\n 1.Add a new user \n\n 2.Sort the existing users \n\n 3.Delete a existing user \n\n 4.Find the median age of all the users ";
	cout<<"\n\n 5.Find the average age of all the users \n\n 6.Find the occupation most users have \n\n 7.Find the locations most users live at ";
	cout<<"\n\n 8.Find users who could be friends of a particular user \n\n 9.Order the list using age of users \n\n 10.reverse the existing list \n\n";
	cout<<" Enter 0 to exit \n";
	
	cout<<"      enter the number corresponding to the choice to proceed \n";
	cin>>choice;
	
	switch(choice){
		
		case 1:add_user(&head);
		break;
		
		case 2:sort_users(&head);
		break;
		
		case 3:system("CLS");
		cout<<"\n Enter the name of the user who you want to delete\n";
		cin>>name_user;
		del_user(search(name_user,head));
		break;
		
		case 0: exit(0);
		
	}
	
	display(&head);
    } //while loop to infinity
    
	return 0;
}


       
