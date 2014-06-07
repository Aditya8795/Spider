#include<iostream>
#include<math.h>

using namespace std;

/* a recurrence relation is an equation that recursively defines a sequence, 
once one or more initial terms are given: each further term of the sequence 
is defined as a function of the preceding terms
the base condition is after we add all the numbers
we can find the kth digit by dividing by 10 to the power n-1 where n is the no of digits of the number after the kth digit
ie in a 10 digit number 1st digit is that number divided by 10 to the power 9, 
the 2nd digit is (the number minus the first digit*(10 to the power 10)) divided by 10 to the power 8 and so on...
the 2nd last digit '' '' '' '' ''    divided by 10
and the last no is the (the number minus the first digit*(10 to the power 10)) moduls with 10 (ie the remainder) 
the case of the last number is taken as the base case..
*/

//finds the sum of all individual digits in the number
int sum_no(int n)
{
	int sum,temp;
	// base condition
	if((n/100)==0)
	{
		sum=(n/10)+(n%10)+sum;
		return sum;
	}
	temp=n/pow(10,log(n));
	sum=sum+temp;
	n=n-(temp*pow(10,log(n)));
	sum_no(n);

}

// driver function

int main()
{
	sum_no(123);
	return 0;
}
