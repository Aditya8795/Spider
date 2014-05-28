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
	    	cout<<"Name No "<<counter<<":- "<<temp->name<<"  Age :- "<<temp->age<<"  Occupation :- "<<temp->occupation<<"  Location :- "<<temp->location<<endl;
	        temp=temp->next;
		    counter++; // keeps track of the nth node (the no)
	    }
	    
	cout<<"Name No "<<counter<<":- "<<temp->name<<"  Age :- "<<temp->age<<"  Occupation :- "<<temp->occupation<<"  Location :- "<<temp->location<<endl;
	
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
	//the logic behind bubble sort has been discussed in the sort_age()

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
	// now the idea is to have temp traverse along the list, 
	node *temp;
	//temp points to the current first node..
	temp=*head;
	node *before;
	node *inserted;
	//incase the after is NULL it means the user has to be inserted at the beginning
	if(after==NULL)
	{
		//after points to the node after which you should insert the user node
		//to solve the dilemma when the node has to be inserted at the beginning, 
		//we pass NULL as the indicator that the point where the insertion has to take place is at the start
		//this is only for the case the first node IS NOT  a having a odd age
		
	    //we create a new node, empty.. 
		//and head points to it now..
		(*head)=new node;
		//we then fill it with user's values
		copy(*head,user);
		//delete the original user
		del_user(user,head);
		//get this new node's pointer to point to the old first node (ie temp)
		(*head)->next=temp;
		//now return the pointer to the newly inserted node!
		return (*head);
	}
	//for other cases.. move along the list
	while(temp->next!=NULL)
	{
		//if we encounter the position where user is to be inserted, ie the pointer after
		if(temp==after)
		{
			//now there are 2 nodes, the NODE 'after' is pointing to, and the one after THAT node
			//set 'before' to point to that node (the one after THAT node).
			before=after->next;
			//allocated the memory for the node that is going to be inserted
			inserted=new node;
			//get the values of the node user and copy them into the node we just made(which inserted points to)
			copy(inserted,user);
			//delete the user node
			del_user(user,head);
			//to set the linked list properly, let the 'after' node point to the inerted node
			after->next=inserted;
			//and the inerted node point to the 'before' node
			inserted->next=before;
			// return the pointer to the node we just inserted
			return inserted;
			
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
			//if its the LAST AS WELL AS THE FIRST NODE
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
	//REFER max_location for the logic, basically copy paste :)
	system("CLS");
	
	node *temp1;
	node *temp2;
	node *ans;
	ans=NULL;
	temp1=head;
	temp2=head;
	char maybe[20];
	int counter=0,lastcounter=1;
	
	if(head==NULL)
	{
		cout<<"\n\n The list is empty!!, so there is no most common occupation "<<endl;
		system("pause>nul");
		return;
		
	}
	//in case there is only a single element in the list
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
		
		if(strcmp(maybe,temp2->occupation)==0)
		{
			counter++;
		}	
		
		if(counter>lastcounter)
		{
			ans=temp1;
			lastcounter=counter;
		}
		
		temp2=head;

		temp1=temp1->next;
	}
	if(ans==NULL)
	{
		cout<<"\n\n In the list there is no most common Occupation "<<endl;
	    system("pause>nul");
	    return;
		
	}
	cout<<"\n\n In the list the most common occupation is: "<<ans->occupation<<endl;
	system("pause>nul");
	return;
	
}

//find the most common occupation among the users
void max_location(node *head)
{
	system("CLS");
	// we do this by taking 2 temporary pointers, both traverse the list in the form of a nested loop
	// temp1 points to a word, then temp2 goes around checking how many OTHER nodes exist with the same location
	node *temp1;
	node *temp2;
	//ans is the pointer to the node which has the maximum occuring location, as far as the loop had gone
	node *ans;
	ans=NULL;
	//start both temp's from head
	temp1=head;
	temp2=head;
	//this is the word that temp1 selects to compare with the rest of the list
	char maybe[20];
	//counter is the current count of the number of times the location being looked into was found
	// and lastcounter is the (as of now) largest count even held by counter
	int counter=0,lastcounter=1;
	
	//check if list is Empty
	if(head==NULL)
	{
		cout<<"\n\n The list is empty!!, so there is no most common location "<<endl;
		system("pause>nul");
		return;
		
	}
	
	//in case if there is only a single element in the list
	if(head->next==NULL)
	{
		cout<<"\n\n The list has only one element, and so the most common location is: "<<head->location<<endl;
		system("pause>nul");
		return;
	}
	
    // the traversing begins
	while(temp1->next!=NULL)
	{
		//the hopefull contenders for "the most common location" is stored in maybe, using temp1 as a handle
		strcpy(maybe,temp1->location);	
		//surveys the whole list looking for all users with the same location	
		while(temp2->next!=NULL)
		{
			if(strcmp(maybe,temp2->location)==0)
			{
				counter++; //increments the counter when such a user is found
			}	
			temp2=temp2->next;
		}
		
		//checks in the case of the last element
		if(strcmp(maybe,temp2->location)==0)
		{
			counter++; //increments the counter when such a user is found
		}	
		
		//after every inner loop we check if this "maybe" is our alltime highest.. 
		if(counter>lastcounter)
		{
			//if so we declare the ans to be temp1(the pointer to this local high "maybe")
			ans=temp1;
			//and set the NEW alltime high
			lastcounter=counter; 
		}
		//reset temp2 as the inner loop has to go all along the list again
		temp2=head;
		//moving on, get to the next "maybe"
		temp1=temp1->next;
	}
	if(ans==NULL)
	{
		cout<<"\n\n In the list there is no most common location "<<endl;
	    system("pause>nul");
	    return;
		
	}
	cout<<"\n\n In the list the most common location is: "<<ans->location<<endl;
	system("pause>nul");
	return;
	
}

//suggest friends based on the conditions(difference in age<15 and either location or occupation is same
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

//maintaining the order it segregates all users with odd ages to the front of the list
void segregate_age(node **head)
{
	system("CLS");
	node *temp;
	temp=*head;
	node *lastodd;
	//as far we know now even the first element is even, if not then in the loop the lastodd will be reset
	lastodd=NULL;
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
	//only 2 nodes in the list
	if((temp->next)->next==NULL)
	{
		if((temp->age)%2==0 && ((temp->next)->age)%2!=0 )
		{
			swap(temp,temp->next);
		}
		cout<<"\n\n\n This List has been Segregated by Age\n\n";
	    system("pause>nul");
		return;
	}
	//here temp traverses the list.. checking for odd aged users
	while(temp->next!=NULL)
	{
		//what happens is they check if the user is odd, if so insert this user at point where the last user's age was odd
		if((temp->age%2)!=0)
		{
		    lastodd=insert(head,temp,lastodd);
		}
		// move along the list..
		temp=temp->next;
	}
	// special case if the last element has a odd age, the loop doest run for the last node
	if((temp->age%2)!=0)
	{
		lastodd=insert(head,temp,lastodd);
	}
	cout<<"\n\n\n This List has been Segregated by Age\n\n";
	system("pause>nul");
}

//reverses the whole list by switching the link (not the data)
void reverse(node **head)
{
	system("CLS");
	//we need 3 pointers which traverse along the linked list
	node *temp,*temp1,*temp2;
	temp=*head;
	if(*head==NULL)
	{
		cout<<"\n\n\n This is a Empty List, Nothing to Reverse.\n\n";
		system("pause>nul");
		return;
	}
	//check if its a list with 1 element
	if(temp->next==NULL)
	{
		cout<<"\n\n\n This is a List with only a single user, Nothing to Reverse\n\n";
		system("pause>nul");
		return;
	}
	// temp then temp1 and finally temp2, they move along the list as a group..
	//as we manipulate the links of any two elements with temp and temp1, we use temp2 to help resume the traversing
	//temp and temp1 serve as the link reversers while temp2 handles the traversing
	temp1=temp->next;
	temp2=temp1->next;
	
	//only 2 nodes in the list
	if((temp->next)->next==NULL)
	{
		//temp is pointing to the first node along with *head(the head pointer)
		//temp1 is pointing to the 2nd AND last node, therefore temp2 is pointing to NULL
		//we set the last node to point to the first node
		temp1->next=temp;
		// set the first element to point to NULL signifying it is now the 2nd AND last node
		temp->next=NULL; //or equal to temp2
		//finally the head pointer is moved to the "previous" second and last node
		*head=temp1;
		cout<<"\n\n\n This List has been Reversed\n\n";
	    system("pause>nul");
		return;
	}
	temp->next=NULL;
	// if 3 or more than 3 elements are there in the list
	while(temp2->next!=NULL)//basically till   ((temp->next)->next)->next)!=NULL
	{
		//the link reversal from temp pointing to what temp1 was pointing to
		temp1->next=temp; // now temp1 is pointing to what temp is pointing to
		//movement of the 3 pointers
		//as temp and temp1 reposition to reverse the next link between the pair of nodes
		temp=temp1;
		temp1=temp2;
		//traversing over the list by temp2
		temp2=temp2->next;
	}
	//now we have to deal with the last 3 nodes..
	temp1->next=temp;
	temp2->next=temp1;
	*head=temp2;
	cout<<"\n\n\n This List has been Reversed\n\n";
	system("pause>nul");
	
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
		
		case 10:reverse(&head);
		break;
		
		case 0: exit(0);
		
	}
	
	display(&head);
	system("CLS");
    } //while loop to infinity
	return 0;
}


       

