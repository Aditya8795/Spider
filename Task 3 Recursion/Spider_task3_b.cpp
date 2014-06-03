#include<iostream>

using namespace std;

//prints numbers from 1 to n in descending order (let this be 'the' series) ( n,(n-1), (n-2), (n-3), (n-4)....... )
void descending_natural(int n)
{
	
	/*if f(i) is the ith term in the series consisting of n terms ( so i
	
	        { n       for i=1
	f(i) =  { f(i)-1  for i>1    (this is the Recursion Relation)
		    { 1       for i=n    (this is the base case)
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
		first we print n ie f(1) as f(1)=n+-1
		then we move on to calling descending_natural(n-1) ie from the recursion condition its f(2) = f(1)-1
		then we move on to calling descending_natural(n-1) again as from the recursion condition f(3) = f(2)-1
		and so on...
		*/
		cout<<"\n"<<n<<"\n";
		descending_natural(n-1);
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
	cout<<"\n\n The Natural numbers from "<<n<<" in descending order is :--\n";
	//start funcyion ascending_natural()
	descending_natural(n);
	
	return 0;
}
