#include<iostream>

using namespace std;

//prints numbers from 1 to n in ascending order (let this be 'the' series) (1, 2, 3, ...... n)
void ascending_natural(int n)
{
	/*if f(i) is the ith term in the series consisting of n terms ( so i
	
	        { 1       for i=1    (this is the base case)
	f(i) =  { f(i)-1  for i>1    (this is the Recursion Relation)
		     
	*/
	
	
	// f(1) is n then f(2) is n-1 and so on...
	
	// check for the base condition here ==> if(i==n) [ie if we reached the last term]
	if(n==1)
	{
		cout<<"\n"<<1<<"\n";
	}
	else
	{
			// the case for all n>1
		/*
		first we call ascending_natural(n-1);
		thus it calls it self by decrementing n each time the call goes through..
		this goes on till the base condition is met and the first term 1 is printed
		then the control shifts back to the previous call which had passed n as 2
		thus 2 is printed
		then the control shifts back to the previous call which had passed n as 3
		thus 3 is printed
		and so on... 
		till...
		the control shifts back to the first call which had passed n as n itself
		thus n is printed
		and the function passes the control to the main function
		*/
		
		ascending_natural(n-1);
		cout<<"\n"<<n<<"\n";
		
	}
	
}

// driver function

int main()
{
	int n;
	
	tryagain:
	
	cout<<"\n\n Enter n \n";
	cin>>n;
	
	//invalid input
	if(n<0)
	{
		cout<<"\n\n invalid input\n TRY AGAIN \n";
		goto tryagain;
		
	}
	cout<<"\n\n The Natural numbers from "<<n<<" in ascending order is :--\n";
	//start funcyion ascending_natural()
	ascending_natural(n);
	
	return 0;
}
