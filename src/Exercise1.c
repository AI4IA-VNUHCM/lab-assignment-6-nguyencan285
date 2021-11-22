/*
1. Receive a maximum 4-digit integer n. Write a program to read the number n.
 ________________________________________________
| Input: 1234                                    |
| Output: one thousand two hundred thirty four   |
|________________________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char* convertIntegerToChar(int n)
{
    int m = n;
    int digit = 0;
    while (m) {
        digit++;
        m /= 10;
    }
    char* arr;
    char arr1[digit];
    arr = (char*)malloc(digit);
    int index = 0;
    while (n) {
        arr1[++index] = n % 10 + '0';
        n /= 10;
    }
    int i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }
    arr[i] = '\0';
    return (char*) arr;
}
 void Number_to_words(char* num)
{
    int len = strlen(num);
 
    
    if (len == 0) {
        printf("Error: empty string !!!\n");
        return;
    }
    if (len > 4) {
        printf("Error: Number length  is more than 4 !!\n");
        return;
    }
 
    
    char* single_digits[]= { "zero", "one", "two",   "three", "four","five", "six", "seven", "eight", "nine" };
 

    char* two_digits[]= { "","ten", "eleven",  "twelve", "thirteen",  "fourteen", "fifteen", "sixteen",
                          "seventeen", "eighteen", "nineteen" };
 
    
    char* tens_multiple[] = { "",   "",   "twenty", "thirty", "forty",   "fifty",
                              "sixty",  "seventy", "eighty","ninety" };
 
    char* tens_power[] = { "hundred", "thousand" };
 

     int flag=1;
     while(flag){
         if(*num-'0'==0){
           ++num;
         }else{
             flag=0;
         }
     }

    len=strlen(num);
    
    if(*num=='\0'){
        printf("zero");
        return;
    }

    if (len == 1) {
        printf("%s", single_digits[*num - '0']);
        return;
    }
 
    
    while (*num != '\0') {
 
        
        if (len >= 3) {
            if (*num - '0' != 0) {
                printf("%s ", single_digits[*num - '0']);
                printf("%s ", tens_power[len - 3]);
                                                   
            }
            --len;
        }
 
        
        else {
            
            if (*num == '1') {
                int sum = *num - '0' + *(num + 1) - '0';
                printf("%s\n", two_digits[sum]);
                return;
            }
 
            
            else if (*num == '2' && *(num + 1) == '0') {
                printf("twenty\n");
                return;
            }

            else {
                int i = *num - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++num;
                if (*num != '0')
                    printf("%s ",single_digits[*num - '0']);
            }
        }
        ++num;
    }
}


void Ex1(int n){
	//Your codes here
	char* arr = convertIntegerToChar(n);
	Number_to_words(arr);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int testcase = atoi(argv[1]);
	
	Ex1(testcase);
	
	return 0;
}
