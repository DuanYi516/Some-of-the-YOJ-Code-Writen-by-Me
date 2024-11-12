#include<stdio.h>
#include<string.h>
#include<math.h>
void int2str(int n,char res[10000]){
    int count=0;
    while(n!=0){
        res[count]=n%10+'0';
        n-=n%10;
        n/=10;
        count++;
    }
    res[count]='\0';
}
int is_not_snake(int n){
    int count=0;
    char string[10000];
    int2str(n,string);
    int len=strlen(string);
    int flag=len/2;
    for(int i=0;i<flag;i++){
        if(string[i]==string[len-1-i]){
            count++;
        }
        else return 1;
    }
    if(count==flag){return 0;}
    else return 1;
}

int reverse(int n){
    char str_n[10000];
    int2str(n,str_n);
    int len=strlen(str_n);
    int result=0;
    for(int i=0;i<len;i++){
        result+=(str_n[i]-'0')*pow(10,len-1-i);
    }
    return result;
}
int main(){
    // int N;scanf("%d",&N);
    int N=196;
    int count=0;
    while(is_not_snake(N)){
        int n_reverse=reverse(N);
        char str_rev[10000];
        int2str(N,str_rev);
        printf("%d+%s=%d\n",N,str_rev,N+n_reverse);
        N+=n_reverse;
        count++;
        if (count>=10){
            break;
        }
        
    }
    if(count==10)printf("Done");
    else    printf("%d is OK",N);
}