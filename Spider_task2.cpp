#include<iostream>

using namespace std;

//prints numbers from 1 to n in ascending order (let this be 'the' series)
void ascending_natural(int n)
{
	int temp;
	/*if f(n) is the nth term in the series 
	f(n) = {1+f(n-1) for n>1   (this is the Recursion Relation)
	       { 1       for n=1   (this is the base case)
	*/
	//base condition
	if(n==1)
	{
		cout<<"\n"<<1<<"\n";
	}
	else
	{
		// the case for all n>0
		cout<<"\n"<<n<<"\n";
		ascending_natural(n-1);
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
	
	//start funcyion ascending_natural()
	ascending_natural(n);
	
	return 0;
}
