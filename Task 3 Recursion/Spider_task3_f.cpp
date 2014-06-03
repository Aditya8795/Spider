 #include<iostream>
 #include<cstdio>
 #include<math.h>
 using namespace std;

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


//here 'from', 'dest', and 'temp' can be 1,2 or 3 depending on whether it is the peg A,B OR C it signifies

void tower_hanoi(int from, int dest, int temp, int disk)
{
	//check for base condition
	if(disk==0)
	{
		cout<<"\n Move disk "<<disk<<" from "<<from<<" to "<<dest<<"\n";
	}
	else
	{
		//as the disk isnt at the top yet we go deeper one more level, by choosing the smaller disk (ans so on... )
		tower_hanoi(from,temp,dest,disk-1);
		//by the time the control passes back here, by recursion, those n-1 disks would have been shifted to dest from from!!
		//now we can just move the LARGE disk from the bottom of from (n) and directly move it to dest
		cout<<"\n Move disk "<<disk<<" from "<<from<<" to "<<dest<<"\n";
	    //we put the nth disk (of this call stack) in the lowest AVAILABLE position in dest
		// we change the lowest available position
		//now we need to get the whole thing set to work for the NEXT call stack where the current (n-1)th stack
		//becomes the nth stack.. so now we need to get the n-1th disk (we have handled the REAL nth disk, as far as we 
		//are concered now we have n-1 disks and 3 EMPTY rods)
		// we could just plainly call the funtion and recursion would handle the rest, handling the largest disk at a time
		// but the n-1 disks are not settled happily in the from rod and the temp rod is not free!
		// after this call stack the temp rod has become the from rod and vice versa.. .so a minor change in arguments
		tower_hanoi(temp,dest,from,disk-1);
	
	}

}

//driver function
int main()
{
	int n;
	
	tryagain:
	
	cout<<"\n\n Enter the total number of disks, for the tower of hanoi \n";
	cin>>n;
	
	//invalid input
	if(n<1)
	{
		cout<<"\n\n invalid input, enter a interger greater than or equal to 1\n TRY AGAIN \n";
		goto tryagain;
	}
	else
	{
		cout<<"\n\n Follow the following "<<pow(2,n)-1<<" steps \n";
	}
	
	//the largest disk is n-1 as its 0th disk, 1st disk, and so on till (n-1)th disk
	//from the 1st rod to the 2nd rod using 3rd rod as temp...
	tower_hanoi(1,2,3,(n-1)); 
	
	cout<<"\n\n We have completed the Tower of Honoi!! \n";

	return 0;
}
