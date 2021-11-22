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

//void Ex2(int n, char *str[]){
//	//Your codes here	
//}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	char *testcase[argc];
	int i,j;
	for(i=0; i<argc; i++){
		testcase[i] = argv[i+1];
	}
	
	//Ex2(argc, testcase);
	char temp[30];
	for (i = 0; i < argc; ++i) {
        for (j = i + 1; j < argc; ++j) {
            
            if ( strcmp(testcase[i], testcase[j]) > 0) 
				{
				
                strcpy(temp, testcase[i]);
                strcpy(testcase[i], testcase[j]);
                strcpy(testcase[j], temp);
                }
        }
    }
	for(i=0;i<argc;i++)
         printf("%s ",testcase[i]);
	return 0;
}
