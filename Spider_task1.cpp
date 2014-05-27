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
         		
	
//Functions that help the 10 functions

//To display the linked list after every operation
void display(node *(*head))
{
	system("CLS");
	
	node *temp;
	temp=*(head);
	int counter=1;
	
	cout<<"DISPLAY OF linked list!! \n\nLinked List is now:--\n";
	
	//traverse along the linked list
	if(temp!=NULL)
	{
	
	    while(temp->next!=NULL)
	    {
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

//searches for a node with a particular name and returns the pointer to him
node* search(char *username, node *localhead)
{
	system("CLS");
	node *temp;
	temp=localhead;
	/*
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
	*/
	
	//ORIGINAL METHOD TO FIND - THE USER TO BE DELETED, above i will try to get the guy before the user (code above)
	
	//check if list is empty
	if(temp!=NULL)
	{
		
	    while(temp->next!=NULL)
		{
			if((strcmpi(temp->name,username)==0))
			{
				//when found send the pointer to the user to the del_user()
				return(temp);
			}
			//move along the list
			temp=temp->next;
		}
		
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
	
	
}


// The 10 Functions

//- a mutator, changes the original list, adds a new node at the end of the list
void add_user(node **head)
{
	system("CLS");
	
	//this a temporary node pointer
	node *temp;
	
	if(*head==NULL)
	{
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
		//basically make the cin IDIOT PROOF
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
	else
	{
		
		//as the list HAS a head node, we set temp to point to the HEAD node
		temp=*head;
		
		//and we use temp to jump along all the linked nodes to the last node in the list
		while(temp->next!=NULL)
		{
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
void sort_users(node **head)
{
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
	char name[20];
	
    system("CLS");
		
	if(user==NULL)
	{
		//this means either empty list OR no such user found
		return;
	}
	else
	{
		//THE one case when you have to delete the LAST element in the list
		if(user->next==NULL)
		{
			cout<<"\n\n look, if the list only has one element and we want to delete it \n then its a special case when we need to set the HEAD pointer to point to NULL, \n so without HEAD pointer i cant delete the one element the list ";
			cout<<"\n\n if its the last element you want to delete, then we cannot get a handle on the \n preceeding node in order to set it as NULL \n";
            //" the head or the previous node has "&user" stored in ITS next attribute!i cant access it!!
            cout<<"\n\n SORRY i was unable to find a way to delete \n";
			system("pause>nul");
			//BUT I AM TELLING YOU GUYS!, look if the list only has one element and we want to delete it
			//then its a special case when we need to set the HEAD pointer to point to NULL, 
			//so without HEAD pointer i cant delete the one element the list
			return;
			// in the case when the list has more than one element when i swap the elements, head points to the location of the "to be deleted node"
			//but i put in the values in that address virtually making head point to the node after the one that is to be deleted
			// this is explained in http://stackoverflow.com/questions/20845301/deleting-previous-node-in-singly-linked-list-if-pointer-to-only-that-given-curre 
		}
			
            //find the name and keep it safe
            strcpy(name,user->name);
  	    temp=user;
  	    
	    //stop traversing at the second to last node,  cause we need to set it's next to NULL
	    while((temp->next)->next!=NULL)
	    {
	    	swap(temp,temp->next);
	    	cout<<"\n swapped \n";
                system("pause>nul");
		//temp to follow the user and stop at the second last node
		temp=temp->next;
	    	
	    }

	    //now we let the user to be deleted swap to the end of the list
	    swap(temp,temp->next);
	
	    //free the memory associated with the user
	    delete (temp->next);
	
	    //set the end of the list at the node where temp is pointing
	    temp->next=NULL;
	
	    cout<<"\n\n"<<name<<" has been deleted \n";
	    system("pause>nul");
		
	}
	
}


int main()
{
	
	int choice=0;
	class node *head = NULL; //THE head (node pointer) is intialized and made to point to NULL
	char name_user[20];
	while(1)
	{
		
	
	cout<<"\n\n\n\n            WELCOME TO THE USER DATA MANAGEMENT MENU";
	cout<<"\n\n 1.Add a new user \n\n 2.Sort the existing users \n\n 3.Delete a existing user \n\n 4.Find the median age of all the users ";
	cout<<"\n\n 5.Find the average age of all the users \n\n 6.Find the occupation most users have \n\n 7.Find the locations most users live at ";
	cout<<"\n\n 8.Find users who could be friends of a particular user \n\n 9.Order the list using age of users \n\n 10.reverse the existing list \n\n";
	cout<<" Enter 0 to exit \n";
	
	cout<<"      enter the number corresponding to the choice to proceed \n";
	cin>>choice;
	
	switch(choice)
	{
		
		case 1:add_user(&head);
		break;
		
		case 2:sort_users(&head);
		break;
		
		case 3:system("CLS");
		cout<<"\n Enter the name of the user who you want to delete\n";
		cin>>name_user;
		del_user(search(name_user,head));
		break;
		
		case 4:
		case 0: exit(0);
		
	}
	
	display(&head);
    } //while loop to infinity
    
	return 0;
}


       
