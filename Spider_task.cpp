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
         
        
// Functions which enable the 10 main functions to work
         
//displays the state of the linked list after every operation
void display(node *(*head))
{
	system("CLS");
	
	node *temp;
	temp=*(head);
	int counter=1;
	
	cout<<"   \n\n\n  DISPLAY OF linked list!! \n\n\n          Linked List is now:--\n";
	
	//traverse along the linked list
	if(temp!=NULL)
	{
	
	    while(temp->next!=NULL)
	    {
	    	cout<<"Name No "<<counter<<":- "<<temp->name<<"  Age :- "<<temp->age<<"  Occupation :- "<<temp->occupation<<"  Location :- "<<temp->location<<"  Gender :- "<<temp->gender<<endl;
	        temp=temp->next;
		    counter++; // keeps track of the nth node (the no)
	    }
	    
	cout<<"Name No "<<counter<<":- "<<temp->name<<"  Age :- "<<temp->age<<"  Occupation :- "<<temp->occupation<<"  Location :- "<<temp->location<<"  Gender :- "<<temp->gender<<endl;
	
	}
	else
	{
		//if the List is Empty
		cout<<"\n\n\n\n          Nothing to display - As list is Empty\n";
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

//this is used to return the node pointer of the user who is to be deleted, using him name..
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

//in order to find median, this sorts the ages
void sort(int a[100], int array_size)
{
	//this implements bubble sort to sort the integer array being passed

	int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
      for (j = 0; j < array_size - 1 - i; ++j )
      {
           if (a[j] > a[j+1])
           {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
           }
      }
    }
	
	
}

//copies the node2 values into node1
void copy(node *node1, node *node2)
{
	//copy individual data attributes
	strcpy(node1->name, node2->name);
	
	node1->age=node2->age;
	
	strcpy(node1->occupation,node2->occupation);

	strcpy(node1->location,node2->location);

	node1->gender=node2->gender;
	//copied!
}


void del_user(node *user, node **head); //Used inside insert function.. as its defined after this.. i have its prototype here

//it takes (the pointer to the node which is to be inserted) and (the pointer to the node after which it has to be inserted) and the address of the head node pointer
//as this function is a mutator and it returns a pointer to the node just inserted
node* insert(node **head, node *user, node *after)
{
	node *temp;
	temp=*head;
	node *temp1;
	node *temp3;
	//incase the after is NULL it means the user has to be inserted at the beginning
	if(after==NULL)
	{
		*head=new node;
		copy(*head,user);
		del_user(user,head);
		(*head)->next=temp;
		return temp;
	}
	while(temp->next!=NULL)
	{
		if(temp==after)
		{
			temp1=temp->next;
			temp3=new node;
			copy(temp3,user);
			del_user(user,head);
			temp->next=temp3;
			temp3->next=temp1;
			return temp3;
			
		}
	}
}

//==================================================================

// the 10 functions

//- a mutator, changes the original list
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
void del_user(node *user, node **head)
{
	//if there are multiple occurences of the same name, then the user closest to the last is deleted, we can write some statements to promt more information
	//temp is used to traverse the list
	node *temp;
	//stores the user's (who is to be deleted) name to display the completion of said task
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
			//using Head pointer
			temp=*head;
			//if its the LAST as well as the first node
			if(user==*head)
			{
				// then all we need to do is set the head to point to NULL, first we delete the node that head and user points to
				delete head; //or delete user;  will also work
				
				//we need the name to be safe..
				strcpy(name,(*head)->name);
				// now to let the rest of the functions know the list is empty and 
				// so that the junk value that is now at the place head was pointing to (&head that was passed as argument) i never used by other functions
				// we set the head pointer to point to null, ie it now stores all zero bits and address zero is deliberately not mapped in into your address space
				// so memory management unit (MMU) wont crah when its accessed..
				*head=NULL;
				cout<<"\n\n"<<name<<" has been deleted \n";
	            system("pause>nul");
				return;
			}
			// in case its not the first AND last node, we find the node before it.. ie the second last node
			while((temp->next)->next!=NULL)
			{
				temp=temp->next;
			}
			// now temp is a handle to the second last node we make IT point to NULL as now ITs the last node
			temp->next=NULL;
			// get the name
			strcpy(name,(user)->name);
			// delete the last node
			delete user;
			cout<<"\n\n"<<name<<" has been deleted \n";
	        system("pause>nul");
			return;
			
			/*
			cout<<"\n\n look if the list only has one element and we want to delete it \n then its a special case when we need to set the HEAD pointer to point to NULL, \n so without HEAD pointer i cant delete the one element the list ";
			cout<<"\n\n if its the last element you want to delete, then we can get a handle on the \n preceeding node in order to set it as NULL \n";
			//" the head or the previous node has "&user" stored in ITS next attribute!i cant access it!!
			system("pause>nul");
			//BUT I AM TELLING YOU GUYS!, look if the list only has one element and we want to delete it
			//then its a special case when we need to set the HEAD pointer to point to NULL, 
			//so without HEAD pointer i cant delete the one element the list
			return;
			// in the case when the list has more than one element when i swap the elements, head points to the location of the "to be deleted node"
			//but i put in the values in that address virtually making head point to the node after the one that is to be deleted
		    */
		}
			
        //find the name and keep it safe
        strcpy(name,user->name);
  	    temp=user;
  	    
	    //stop traversing at the second to last node,  cause we need to set it's next to NULL
	    while((temp->next)->next!=NULL)
	    {
	    	swap(temp,temp->next);
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

//to find the median age of the users in the linked list
void median_age(node *head)
{
	system("CLS");
	//n is used to store no of nodes
	int n=1;
	
	//checks if the list is empty
	if(head==NULL)
	{
		cout<<"\n\n The list is empty, NO median exists"<<endl;
		system("pause>nul");
		return;
		
	}
	//checks if the list has only one element
	if(head->next==NULL)
	{
		cout<<"\n\n The list has only one element, the median is: "<<head->age<<endl;
		system("pause>nul");
		return;
	}
	
	node *temp;
	temp=head;
	// a holds all the ages of the users in a integer array, b is used for median calculation
	int a[100],b;
	//median is used to store the answer
	float median;

	//to find the number of nodes, n and to form the array a, which holds all the ages
	while(temp->next!=NULL)
	{
		//traverse through the list storing each users age into the integer array for manipulation
		a[n-1]=temp->age;
		n++;
		temp=temp->next;
		
	}
	// store the last node's age
	a[n-1]=temp->age;
	
	// make the ages in order, this is a mutator function
	sort(a,n);
	
	//print the median in case of a 2 element list
	if(n==2)
	{
		median=(a[0]+a[1])/2;
		cout<<"\n\n for the 2 element list, The median is "<<median<<endl;
		system("pause>nul");
		return;
    }
	//in case of 2n or 2n+1 no of users, after sorting the ages, the median varies.. that is calculated
	if(n%2==0)
	{
		b=(n/2)-1;
		median=(a[b]+a[b+1])/2;
		cout<<"\n\n The median is "<<median<<endl;
	}
	else
	{
		cout<<"\n\n The median is "<<a[(n/2)]<<endl;
	}
	
	system("pause>nul");
}

//find the average of the ages of all users
void average_age(node *head)
{
	system("CLS");
	//sum/n is average, ie sum is the total sum of all ages and n is the number of such ages
	float sum=0,n=1,average;
	node *temp;
	temp=head;
	
	//in case of empty list
	if(head==NULL)
	{
		cout<<"\n\n The list is empty, NO Average exists"<<endl;
		system("pause>nul");
		return;
		
	}
	
	//in case os only a single element in the list
	if(head->next==NULL)
	{
		cout<<"\n\n The list has only one element, the average age is: "<<head->age<<endl;
		system("pause>nul");
		return;
	}
	
	//find the number of nodes and find the sum of all ages
	while(temp->next!=NULL)
	{
		//traverse along the linked list, adding each age to sum
		sum=sum+(temp->age);
		temp=temp->next;
		n++;
	}
	//calculate average and print
	average=(sum+(temp->age))/n;
	cout<<"\n\n The average age is: "<<average<<endl;
	system("pause>nul");
	return;
	
}

//find the most common occupation among the users
void max_occupation(node *head)
{
	system("CLS");
	
	node *temp1;
	node *temp2;
	node *ans;
	temp1=head;
	temp2=head;
	char maybe[20];
	int counter=0,lastcounter=0;
	
	if(head==NULL)
	{
		cout<<"\n\n The list is empty!!"<<endl;
		system("pause>nul");
		return;
		
	}
	//in case os only a single element in the list
	if(head->next==NULL)
	{
		cout<<"\n\n The list has only one element, and so the most common occupation is: "<<head->occupation<<endl;
		system("pause>nul");
		return;
	}

	while(temp1->next!=NULL)
	{

		strcpy(maybe,temp1->occupation);
		
		while(temp2->next!=NULL)
		{
			if(strcmp(maybe,temp2->occupation)==0)
			{
				counter++;
			}	
			temp2=temp2->next;
		}
		
		if(counter>lastcounter)
		{
			ans=temp1;
			lastcounter=counter;
		}
		
		temp2=head;

		temp1=temp1->next;
	}
	
	cout<<"\n\n In the list the most common occupation is: "<<ans->occupation<<endl;
	system("pause>nul");
	return;
	
}

//find the most common occupation among the users
void max_location(node *head)
{
	system("CLS");
	// we do this by taking 2 temporary pointers, both traverse the list in a double loop
	// 
	node *temp1;
	node *temp2;
	node *ans;
	temp1=head;
	temp2=head;
	char maybe[20];
	int counter=0,lastcounter=0;
	
	if(head==NULL)
	{
		cout<<"\n\n The list is empty!!"<<endl;
		system("pause>nul");
		return;
		
	}
	//in case os only a single element in the list
	if(head->next==NULL)
	{
		cout<<"\n\n The list has only one element, and so the most common location is: "<<head->location<<endl;
		system("pause>nul");
		return;
	}

	while(temp1->next!=NULL)
	{

		strcpy(maybe,temp1->location);
		
		while(temp2->next!=NULL)
		{
			if(strcmp(maybe,temp2->location)==0)
			{
				counter++;
			}	
			temp2=temp2->next;
		}
		
		if(counter>lastcounter)
		{
			ans=temp1;
			lastcounter=counter;
		}
		
		temp2=head;

		temp1=temp1->next;
	}
	
	cout<<"\n\n In the list the most common location is: "<<ans->location<<endl;
	system("pause>nul");
	return;
	
}

void suggest_friends(node *head)
{
	system("CLS");
	
	node *temp;
	node *lonely;
	temp=head;
	char user[20];
	int found=0;
	
	if(head==NULL)
	{
		cout<<"\n\n The list is empty!!"<<endl;
		system("pause>nul");
		return;
		
	}
	
	cout<<"\n\n Enter the user you want to find friends for \n";
	cin>>user;
	
	//in case os only a single element in the list
	if(head->next==NULL)
	{
		cout<<"\n\n The list has only one element, and so there is no friends we can suggest: "<<endl;
		system("pause>nul");
		return;
	}
	
	lonely=search(user,head);
	
	if(lonely==NULL)
	{
		return;
	}
	
	while(temp->next!=NULL)
	{
		if(temp==lonely)
		{
			temp=temp->next;
			continue;
		}
		if(strcmp(lonely->location,temp->location)==0 || strcmp(lonely->occupation,temp->occupation)==0 )
		{
			if((lonely->age)>=(temp->age))
			{
				if((lonely->age)-(temp->age)<15)
				{
					cout<<temp->name<<"\n Could be your friend!!"<<endl;
		            system("pause>nul");
		            found=1;
				}
			}
			else
			{
				if(((temp->age)-(lonely->age))<15)
				{
					cout<<temp->name<<"\n Could be your friend!!"<<endl;
		            system("pause>nul");
		            found=1;
				}
				
			}
		}
		
		temp=temp->next;
	}

    if((strcmp(lonely->location,temp->location)==0 || strcmp(lonely->occupation,temp->occupation)==0)&& temp!=lonely)
    {
		if((lonely->age)>=(temp->age))
		{
			if((lonely->age)-(temp->age)<15)
			{
					cout<<temp->name<<"\n Could be your friend!!"<<endl;
		            system("pause>nul");
		            found=1;
			}
		}
		else
		{
			if(((temp->age)-(lonely->age))<15)
			{
					cout<<temp->name<<"\n Could be your friend!!"<<endl;
		            system("pause>nul");
		            found=1;
			}
				
		}
	
	}
	if(found==0)
	{
			cout<<"No friends could be Found!! :(";
			system("pause>nul");
	}
	return;
}

void segregate_age(node **head)
{
	system("CLS");
	node *temp;
	temp=*head;
	node *temp1;
	
	//check if its a Empty List
	if(*head==NULL)
	{
		cout<<"\n\n\n This is a Empty List, Nothing to Segregate by Age.\n\n";
		system("pause>nul");
		return;
	}
	//check if its a list with 1 element
	if(temp->next==NULL)
	{
		cout<<"\n\n\n This is a List with only a single user, Cant Segregate by Age\n\n";
		system("pause>nul");
		return;
	}
	while(temp->next!=NULL)
	{
		cout<<"\n list has more than 1 element \n";
		if((temp->age%2)!=0)
		{
			cout<<"\n this number is odd \n";
			if(temp==*head)
			{
				cout<<"the first number is odd so ignore..";
				temp1=temp;
				temp=temp->next;
				continue;
		    }
		    temp1=insert(head,temp,temp1);
		}
		cout<<"\n finished a user now \n";
		temp=temp->next;
	}
	if((temp->age%2)!=0)
	{
		cout<<"\n this is the last element\n";
		temp1=insert(head,temp,temp1);
	}
}

// the driver function for implementing the 10 Functions in a menu form
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
		del_user(search(name_user,head),&head);
		break;
		
		case 4:median_age(head);
		break;
		
		case 5:average_age(head);
		break;
		
		case 6:max_occupation(head);
		break;
		
		case 7:max_location(head);
		break;
		
		case 8:suggest_friends(head);
		break;
		
		case 9:segregate_age(&head);
		break;
		
		case 0: exit(0);
		
	}
	
	display(&head);
	system("CLS");
    } //while loop to infinity
    cout<<"\ncheck\n";
    system("pause>nul");
	return 0;
}


       

