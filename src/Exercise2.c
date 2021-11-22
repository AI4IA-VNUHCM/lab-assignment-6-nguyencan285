/*
2. Receive n strings from the input and sort them ascendingly.
Ex:
 _________________________________________
| Input: one two three                    |
| Output: one three two                   |
|_________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void Ex2(int n, char *str[])
{
	
	//Your codes here	
	char *temp[100];
	int index[n];
	for(int i=0;i<n;i++)
	index[i]=i;
		for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
		{	int t=0;
			while(str[index[i]][t]!='\0')
			{
			if(str[index[i]][t]>str[index[j]][t])
				{
				int temp=index[i];
				index[i] = index[j];
				index[j] = temp;
				}
				else if(str[index[i]][t]==str[index[j]][t])
				t++;
				else
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
        printf("%s ",str[index[i]]);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	char *testcase[argc];
	int i;
	for(i=0; i<argc; i++){
		testcase[i] = argv[i+1];
	}
	
	Ex2(argc, testcase);
	
	return 0;
}
