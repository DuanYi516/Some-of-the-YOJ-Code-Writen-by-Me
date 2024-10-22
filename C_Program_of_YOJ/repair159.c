#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(char *STRING,char*str,int len_str);
char* delete(char *STRING,char*str,int len_str);
char* insert(char *STRING,char*str1,char *str2);
char* rehave(char *STRING,char*str1,char *str2);
int main(){
    FILE *file = fopen("error_290_ck14.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    char STRING[100];fgets(STRING, sizeof(STRING), stdin);
    //char enter;enter=getchar();
    char choice;choice=getchar();
    char str1[100];scanf("%s",str1);
    
    int len_str1=strlen(str1);
    if(choice=='C'){
        printf("%d",compare(STRING,str1,len_str1));
    }
    else if(choice=='D'){
        printf("%s",delete(STRING,str1,len_str1));
    }
    else if(choice=='I'){
        char str2[100];scanf("%s",str2);
        int len_str2=strlen(str2);
        printf("%s",insert(STRING,str1,str2));
    }
   else if(choice=='R'){
        char str2[100];scanf("%s",str2);
        printf("%s",rehave(STRING,str1,str2));
   }
    return 0;
}

int compare(char *STRING,char*str,int len_str){
    int LEN=strlen(STRING);
    int count=0;
    for(int i=0;i<LEN-len_str+1;i++){
        int flag=0;
        for(int j=0;j<len_str;j++){
            if(STRING[i+j]==str[j]){
                flag++;
            }
            else break;
        }
        if(flag==len_str){
            count++;
        }
    }
    return count;
}
char*delete(char *STRING,char*str,int len_str){
    int LEN=strlen(STRING);
    char copy_STRING[100];
    for(int i=0;i<LEN;i++)copy_STRING[i]=STRING[i];
    for(int i=0;i<LEN-len_str;i++){
        int flag=0;
        for(int j=0;j<len_str;j++){
            if(STRING[i+j]==str[j]){
                flag++;
            }
            else break;
        }
        if(flag==len_str){
            for(int j=0;j<LEN-len_str-i;j++){
                STRING[i+j]=copy_STRING[i+len_str+j];
            }
            STRING[LEN-len_str]='\0';
            break;
        }
        
    }
    return STRING;
}
char* insert(char *STRING,char*str1,char *str2){
    int LEN=strlen(STRING),len_str1=strlen(str1),len_str2=strlen(str2);
    char copy_STRING[100];
    for(int i=0;i<LEN;i++)copy_STRING[i]=STRING[i];
    for(int i=LEN-1;i>0;i--){
        int flag=0;
        for(int j=0;j<len_str1;j++){
            if(STRING[i-len_str1+1+j]==str1[j]){
                flag++;
            }
            else break;
        }
        if(flag==len_str1){
            for(int j=0;j<len_str2;j++){
                STRING[i-len_str1+1+j]=str2[j];
            }
            for(int j=0;j<LEN-i+len_str1;j++){
                STRING[i-len_str1+len_str2+j+1]=copy_STRING[i-len_str1+1+j];
            }
            break;
        }
    }
    return STRING;
}
char *rehave(char *STRING,char*str1,char *str2){
    int LEN=strlen(STRING),len_str1=strlen(str1),len_str2=strlen(str2);
    char copy_STRING[100];
    for(int i=0;i<LEN;i++)copy_STRING[i]=STRING[i];
    int count=0;
    for (int i = 0; i < LEN; i++){
        int flag=0;
        for(int j=0;j<len_str1;j++){
            if(copy_STRING[i+j]==str1[j]){
                flag++;
            }
            else break;
        }
        if(flag==len_str1){
            for(int j=0;j<len_str2;j++){
                STRING[i+j+count*(len_str2-len_str1)]=str2[j];
            }
            for(int j=0;j<LEN-i-len_str1;j++){
                STRING[i+len_str2+j]=copy_STRING[i+len_str1+j];
            }
            count++;
        }
    }
    STRING[LEN+count*(len_str2-len_str1)]='\0';
    return STRING;
}