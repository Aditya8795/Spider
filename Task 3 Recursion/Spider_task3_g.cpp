#include<iostream>
#include<string.h>

using namespace std;

/* a recurrence relation is an equation that recursively defines a sequence, 
once one or more initial terms are given: each further term of the sequence 
is defined as a function of the preceding terms
ie, here 

we take the 
*/

//reverses the string that comes in as argument
void reverse(char str[30],int index)
{
	if(strlen(str)%2==0 && index==(strlen(str)/2-1))
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
	return 0;
}
