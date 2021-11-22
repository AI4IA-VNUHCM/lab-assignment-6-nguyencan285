/*
5. Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. The brackets must close in the correct order.
Ex:
 ________________________
| Input: "{([])}"        |
| Output: Valid!         |
| Input: "{[)}"          |
| Output: Invalid!       |
|________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char bracket(char ch)
{
	if(ch == '(')
	return')';
	if(ch== '{')
	return'}';
	if(ch== '[')
	return ']';
	return -1;
}
int check(char str[],int n)
{
	if(n==0)
	return 1;
	if (n==1)
	return 0;
	if(str[0]==')'|| str[0]=='}'||str[0]==']')
	return 0;
	char ngoac= bracket(str[0]);
	int i,count=0;
	for(i=1;i<n;i++){
		if(str[i]== ngoac){
			if (count==0)
			break;
			count--;
		}
	}
	if(i==n)
	return 0;
	if(i==1)
	return check(str+2,n-2);
	return check(str+1,i-1)&&check(str+i+1,n-i-1);
}
void Ex5(char *str){
	//Your codes here
	int n= strlen(str);
	if(check(str,n))
	printf("Valid!");
	else
	printf("Invalid!");

	
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *testcase = argv[1];
	Ex5(testcase);
	return 0;
}
