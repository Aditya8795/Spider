#include<iostream>
#include<string.h>
#include<cstdio>

using namespace std;

// e is the finite collection of symbols and n is the length of the string (finite, ie equals k)
// this function prints all the strings over the 'alphabet' e which are of n length (ie each string to be printed has n elements)
// the input symbols are k in length, ie the 'alphabet' e has k elements


void print_strings(char e[30],char string[30], int n, int index)
{
	if(strlen(string)==n)
	{
		index--;
		cout<<string<<"\n";
		string[index]=NULL;
		return;
	}

	for(int i=0;i<strlen(e);i++)
	{
		string[index]=e[i];
		print_strings(e,string,n,index+1);
	}
	
}
// for appending to a string
//string+=e[i];  // we could also have done string.push_back(e[i]);

int main()
{
	char input[30]="#@%$&%";
	char str[30];
	
	strcpy(str,"");

	int str_size=2;

	print_strings(input,str,str_size,0);
	
	return 0;
}
