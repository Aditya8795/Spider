 #include<iostream>
 
 using namespace std;

// returns true if n is prime and returns false n is NOT prime ( n should be no more than 6 digits )

/*
the recursion relation:-
n is NOT prime if n is divisible by any number Other Than 1 and n itself
so we check using the check variable
we check if it divisible with int(n/2) ( which is the integer part of the float (n/2) )
this relation
*/
bool is_prime(int n,int check)
{
	if(check==1)
	{
		return true;
	}
	else
	{
		if(n%check!=0)
		{
			is_prime(n,check-1); // difference between return is_prime() and just is_prime()
		}
		else
		{
			return false;
		}
	}
}

//driver function

int main()
{
	int n;
	
	tryagain:
	
	cout<<"\n\n Enter n to check if n is prime (n>1) \n";
	cin>>n;
	
	//invalid input
	if(n<=1)
	{
		cout<<"\n\n invalid input\n TRY AGAIN \n";
		goto tryagain;
		
	}
		//start function is_prime() and print output
    if(is_prime(n,(n/2)))
    {
    	cout<<"\n\n The number "<<n<<" is a Prime Number \n";
    }
    else
    {
    	cout<<"\n\n The number "<<n<<" is NOT a Prime Number \n";
    }
	
    goto tryagain;
	return 0;
}
