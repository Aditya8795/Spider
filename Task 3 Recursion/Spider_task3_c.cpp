 #include<iostream>
 
 using namespace std;

// returns true if n is prime and returns false n is NOT prime ( n should be no more than 6 digits )

/*
the recursion relation:-
n is NOT prime if n is divisible by any number Other Than 1 and n itself
so we check using the check variable
we check if it divisible with int(n/2) ( which is the integer part of the float (n/2) )
this is the recursive relation.

but as far as i understood a recurrence relation is an equation that recursively defines a sequence, 
once one or more initial terms are given: each further term of the sequence is defined as a function 
of the preceding terms,here the sequence is irrational, its either true,true,false,true,.....or 2,3,5,etc
so we cant represent the sequence of all prime numbers

The base condition is that 
if n is divisible by check, it is not prime, so return false
also if we have checked all numbers(check has decremented till check==1) without triggering the previous base condition, then the number is not prime
*/
bool is_prime(int n,int check)
{
	//this is the base condition for it to be a prime number
	if(check==1)
	{
		return true;
	}
	else
	{
		if(n%check!=0)
		{
			//the recursive condition is implemented here as check moves from n/2 to 1 while recursivly calling the function
			
			is_prime(n,check-1); // difference between return is_prime() and just is_prime()
		}
		else
		{
			// this is the base condition for it NOT to be a prime number
			return false;
		}
	}
}

//driver function

int main()
{
	int n;
	
	tryagain:
	
	cout<<"\n\n Enter n to check if n is prime \n";
	cin>>n;
	
	//invalid input
	if(n<=1)
	{
		cout<<"\n\n invalid input, enter a interger greater than 1\n TRY AGAIN \n";
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
