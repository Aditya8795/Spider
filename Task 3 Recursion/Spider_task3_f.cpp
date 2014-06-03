 #include<iostream>
 #include <cstdio>
 using namespace std;


//diplay function
void display(int a[50], int b[50], int c[50], int f, int d, int t)
{
	int i;
	//print a the SOURCE
	cout<<"\n A \n";
	for(i=0;i<f;i++)
	{
		//store the values in the source rod
		cout<<"\t"<<a[i]<<"\t";
	}
	//print B the DESTINATION
	cout<<"\n B \n";
	for(i=0;i<d;i++)
	{
		//store the values in the source rod
		cout<<"\t"<<b[i]<<"\t";
	}
	//print C the TEMP
	cout<<"\n C \n";
	for(i=0;i<f;i++)
	{
		//store the values in the source rod
		cout<<"\t"<<c[i]<<"\t";
	}
	//getchar();
}

/*
In the Tower Of Hanoi Problem, we have the 3 Rods A, B, and C
The disks are notated by numbers, 1 is the smallest disk, then 2,3,4.... till n the largest disk.
we use integer arrays a[50], b[50], and c[50] to denote the rods A, B, and C
a[0], b[0], and c[0] is the lowest point (the bottom) of the rods respectivly

As we know our objective is to move the entire stack of disks to another rod by performing operations,
each operation has to follow these rules,
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks
   and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
   ie, we can only manipulate the last element in the a,b and c arrays.
3. No disk may be placed on top of a smaller disk.

Algorithm:
Now every operation can be defined with these parameters...
the FROM rod, the TO rod and the TEMP rod (we can say if a and b is the first 2 then c is the 3rd but i think all 3 have to
be passed as arguments, otherwise i will have to write a lot of if statements covering the 3 possibilities)
and the DISK which is to be moved(the largest disk in the tower from which we want to move the disk).
so in order to move the n disks from A to B, we perform it in 3 Parts
1) we move all disks except n (ie, (n-1) to 1) from A to C using C (as spare) (calls the function itself)
2) now we can move the disk n from A to B DIRECTLY (as the rest of the disks are on C )(THIS IS A BASE CONDITION)
3) now B is basically like a empty rod as Rule no 3 doesnt appy to it, as all the n-1 disks are larger
   than it.
   So we can now Repeat the above step 1 recursivley to move the (n-1)th disk to B 
   then n-2, and so on.... (so this also calls the function itself)

ALSO we establish the base condition as when the disk is the smallest 
in that particular rod(ie when we are at the top of the array) we simply MOVE THE DISK


The recursive Relation is an equation that recursively defines a sequence, 
once one or more initial terms are given: each further term of the sequence 
is defined as a function of the preceding terms
T(n) is the minimum number of moves requried to perform the tower of hanoi
as its known, 
T(1)=1
T(2)=3
T(3)=7
.....
now as we know from the algorithm we formulated above,
part 1 requires T(n-1) moves as its recursion
part 2 requires 1 step, as its a base condition
part 3 again requires T(n-1) steps

so, T(n)=T(n-1)+1+T(n-1)
so...  T(n)=2*T(n-1)+1 

*/

//here f,d, and t are the top indexes of the arrays to keep us informed that
//from[f], dest[d] and temp[t] are the top most elements in the array (rod) (the ones that can be moved)
//and bottom_dest keeps track of the dest buildup, as we fill in the larger disks in proper order 
//we dont disturb the arranged disks (disks on and below dest[bottom_dest])
void tower_hanoi(int from[50], int dest[50], int temp[50], int disk, int f, int d, int t, int bottom_dest=0)
{
	//check for base condition
	if(disk==0)
	{
		// at dest[d] the previous top element was stored
		d++; //update the top element of the dest
		//move the disk directly to dest from from :)
		dest[d]=from[f];
		f--; // virtually delete the top element of from
	}
	else
	{
		//as the disk isnt at the top yet we go deeper one more level, by choosing the smaller disk (ans so on... )
		tower_hanoi(from,dest,temp,disk-1,f,d,t,bottom_dest);
		//by the time the control passes back here, by recursion, those n-1 disks would have been shifted to dest from from!!
		//now we can just move the LARGE disk from the bottom of from (n) and directly move it to dest
		dest[bottom_dest]=from[0]; //we put the nth disk (of this call stack) in the lowest AVAILABLE position in dest
		bottom_dest++; // we change the lowest available position
		//now we need to get the whole thing set to work for the NEXT call stack where the current (n-1)th stack
		//becomes the nth stack.. so now we need to get the n-1th disk (we have handled the REAL nth disk, as far as we 
		//are concered now we have n-1 disks and 3 EMPTY rods)
		// we could just plainly call the funtion and recursion would handle the rest, handling the largest disk at a time
		// but the n-1 disks are not settled happily in the from rod and the temp rod is not free!
		// after this call stack the temp rod has become the from rod and vice versa.. .so a minor change in arguments
		tower_hanoi(temp,dest,from,disk-1,f,d,t,bottom_dest);
	
	}

}

//driver function
int main()
{
	int a[50],b[50],c[50],n,i;
	
	tryagain:
	
	cout<<"\n\n Enter the total number of disk, for the tower of hanoi \n";
	cin>>n;
	
	//invalid input
	if(n<1)
	{
		cout<<"\n\n invalid input, enter a interger greater than or equal to 1\n TRY AGAIN \n";
		goto tryagain;
	}
	
	//assemble the tower..
	for(i=0;i<n;i++)
	{
		//store the values in the source rod
		a[i]=n-i-1;
	}
	cout<<a[0]<<"\t";
	cout<<a[1]<<"\t";
	cout<<a[2]<<"\t\n";
	//the largest disk is n-1 at the (n-1)th index of a
	tower_hanoi(a,b,c,(n-1),(n-1),-1,-1); 
	// -1 index informs them that the rod is EMPTY,0 would have ment the first element is occupied
	cout<<b[0]<<"\n\t";
	cout<<b[1]<<"\t";
	cout<<b[2]<<"\t\n";
	cout<<a[0]<<"\t";
	cout<<a[1]<<"\t";
	cout<<a[2]<<"\t\n";

	return 0;
}
