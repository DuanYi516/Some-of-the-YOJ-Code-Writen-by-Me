#include<stdio.h>
#include<string.h>
int only_star(char *s){
    int len=strlen(s);
    int flag=0;
    for(int i=0;i<len;i++){
        if(s[i]=='*')flag++;
    }
    return (flag==len);
}
int not_have_star(char *s){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='*')return 0;
    }
    return 1;
}
void erase(char *s,char *res){
    if(s[0]=='\0'||only_star(s)){
        strcpy(res,"*NULL*");
    }else if(not_have_star(s)){
        strcpy(res,s);
    }else{
        int len=strlen(s);
        char new[2001];
        int new_len=1;
        new[0]=s[0];
        for(int i=1;i<len;i++){
            if(s[i]!='*'){
                new[new_len]=s[i];
                new_len++;
            }else{
                if(new_len>=1){new_len--;}
                else{new_len=0;}
                new[new_len]='\0';
            }
        }
        erase(new,res);
    }
}
int main(){
    int m=1;scanf("%d",&m);
    char s[10][2001];
    // char s[200]="0*3*2V1M*q**42***w*g*j*P**7**S7Z*X***l**2**U**p*6O";
        
    for(int i=0;i<m;i++){
        scanf("%s",s[i]);
        erase(s[i],s[i]);
    }
    for(int i=0;i<m;i++){
        puts(s[i]);
        // printf("%s\n",s[i]);
    }
    return 0;
}
