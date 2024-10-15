#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int replaceStr(char A[ ], const char B[ ], const char C[ ]){
    //补充代码，完成此函数
    int len_a=strlen(A),len_b=strlen(B),len_c=strlen(C);
    int _case=0;
    int start=0;
    char copy_A[100];
    for(int i=0;i<len_a;i++)copy_A[i]=A[i];
    for(int i=0;i<len_a-len_b;i++){
        int flag;
        for(int letter=0;letter<len_b;letter++){
            if(A[i+letter]!=B[letter])break;
            flag++;
        }
        if(flag==len_b){
            _case=1;
            start = i;
            break;
        }
    }
    if(_case){
        for(int i=0;i<len_c;i++){
            A[i+start]=C[i];
        }
        for(int i=0;i<len_a-start-len_b;i++){
            A[i+start+len_c]=copy_A[i+start+len_b];
        }
        for(int i=0;i<len_b-len_c;i++){
            A[i+len_a+len_c-len_b]='\0';
        }
        return 1;
    }
    else {
        for(int i=0;i<len_c;i++){
            A[len_a+i]=C[i];
        }
        return 0;
        }
}
int main(){
    char str1[110]="Hello world!", str2[110]="wor", str3[110]="baby";
    int nRes;
    // cin.getline(str1, 100);
    // cin.getline(str2, 100);
    // cin.getline(str3, 100);
    
    nRes = replaceStr(str1, str2, str3);
    printf("%d", nRes);
    printf("%s", str1);
    return 0;
}