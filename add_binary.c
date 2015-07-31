/*
 *  Add Binary 
 *  Given two binary strings, return their sum (also a binary string).
 *  For example,a = "11",b = "1",Return "100".
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len   = (len_a > len_b) ? (len_a+2):(len_b+2);
    
    int carry = 0;
    char *res = (char *) malloc(sizeof(char) * len);
    
    int k = len-2;
    int i = len_a-1, j = len_b-1;
    
    for(; i >= 0 && j >= 0; i--, j--)
    {
		printf("%c",a[j]);
        int bit = (a[i]-'0') + (a[j]-'0') + carry;
        if(bit > 1) {
            carry = 1;
            bit = 0;
        }
        
        res[k--] = bit + '0';
    }
    
    while(i >= 0) {
        int bit = (a[i]-'0') + carry;
        if(bit > 1) {
            carry = 1;
            bit = 0;
            res[k--] = bit + '0';
        }
        --i;
    }
    
    while(j >= 0) {
        int bit = (a[j]-'0') + carry;
        if(bit > 1) {
            carry = 1;
            bit = 0;
            res[k--] = bit + '0';
        }
        --j;
    }
    
    if(carry != 0) {
        res[k--] = carry+'0';
    }
    else
		res[k--] = '0';
    res[len-1] = '\0';

    
    return (res[0] == '0')?(res+1) : res;
}

void main()
{
	char a[]= {'0','\0'};
	char b[] = {'1','\0'};
	char *c = addBinary( a,  b);
	int len = strlen(c);
	for(int i = 0 ; i < len; i++)
		printf("%c ", c[i]);
}
