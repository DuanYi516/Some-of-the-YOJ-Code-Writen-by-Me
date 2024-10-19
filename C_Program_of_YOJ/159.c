/*给定一个字符串，其长度不超过200，现需要通过一行文本命令（文本命令长度不超过100个字符），
对其进行编辑或统计。相应的功能有：

·统计子串：C str
命令格式为一行，包含一个字符C和一个字符串，之间有一个空格隔开。
功能：统计子串str在给定的字符串中无重叠的出现次数。

·删除子串：D str
命令格式为一行，包含一个字符D和一个字符串，之间有一个空格隔开。
功能：删除原字符串中的子串str，若有多个子串str，则删除第一次出现的，若找不到str则不做任何操作
*/
/*
·插入子串： I str1 str2
命令格式为一行，包含一个字符I和2个字符串，每两项之间用一个空格隔开。
功能：表示将子串str2插入到子串str1的前面。若原串中有多个str1，则插入在最后一个子串的前面，若找不到str则不做任何操作。

·替换子串：R str1 str2
命令格式为一行，报告一个字符R和2个字符串，每两项之间用一个空格隔开。
功能：表示在原字符串中用str2替换str1，str1为被替换的子串，str2为替换的子串，
若在原串中有多个str1则应全部替换。但当替换进去的子串与原串拼接后新出现子串str1时，不用再替换。
若找不到str则不做任何操作。*/

#include<stdio.h>
#include<string.h>
int compare(char *STRING,char*str);
char* delete(char *STRING,char*str);
// char* insert(char *STRING,char*str1,char *str2);
// char* rehave(char *STRING,char*str1,char *str2);

int main(){
    char STRING[100];scanf("%s",STRING);
    char how[200];scanf("%s",how);
    char *str1;
    char *str2;
    char *c;
    c = strtok(how," ");
    str1=strtok(NULL," ");
    str2=strtok(NULL," ");
    char choice=c[0];
    if(choice=='C'){
        printf("%d",compare(STRING,str1));
    }
    else if(choice=='D'){
        printf("%s",delete(STRING,str1));
    }
    // else if(choice=='I'){
    //     printf("%s",insert(STRING,str1,str2));
    // }
    // else if(choice=='R'){
    //     printf("%s",rehave(STRING,str1,str2));
    // }
    return 0;
}

int compare(char *STRING,char*str){
    int LEN=strlen(STRING),len_str=strlen(str);
    int count=0;
    for(int i=0;i<LEN-len_str;i++){
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
char*delete(char *STRING,char*str){
    int LEN=strlen(STRING),len_str=strlen(str);
    char *copy_STRING;
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
        }
    }
    return STRING;
}