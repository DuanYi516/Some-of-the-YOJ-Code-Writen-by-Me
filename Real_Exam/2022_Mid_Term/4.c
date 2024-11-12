#include<stdio.h>
#include<string.h>
struct type_dict{
    char word[120];
    int count;
};
int main(){
    char sentence[1200];gets(sentence);
    struct type_dict my_dict[10];
    char *token;
    token=strtok(sentence," ");
    while(1);
}
