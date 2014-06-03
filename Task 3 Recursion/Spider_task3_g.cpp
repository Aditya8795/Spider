#include<iostream>
#include<string.h>
#include<cstdio>

using namespace std;

/* a recurrence relation is an equation that recursively defines a sequence, 
once one or more initial terms are given: each further term of the sequence 
is defined as a function of the preceding terms
ie, here if f(i) is the ith character of the string (i is 0,1,2,3... like char array)
we need to swap the f(i) and f(n-1-i)th character
the base condition is
if n is even and the swaping index variable reaches n/2 (has to swap the case when i=i/2 then stop)
if n is odd swap when i=(n/2)+1 and stop
we take the 
*/

//reverses the string that comes in as argument
void reverse(char str[30],int index)
{
	// base condition
	if((strlen(str)%2==0 && index==((strlen(str)/2)-1)) || (strlen(str)%2!=0 && index==((strlen(str)/2))))
	{
		return;
	}
	char temp;
	temp=str[index];
	str[index]=str[strlen(str)-1-index];
	str[strlen(str)-1-index]=temp;
	index--;
	reverse(str,index);

}

// driver function

int main()
{
	char word[30];
	cout<<"\n\n Enter the Word!!\n";
	cin>>word;
	
	int len=strlen(word)-1;
	
	reverse(word,len);

	cout<<word;
	
	getchar();
	return 0;
}
