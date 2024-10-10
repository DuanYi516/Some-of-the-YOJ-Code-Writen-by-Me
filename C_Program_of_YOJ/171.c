#include<stdio.h>
int main(){
    int a,b;
    char c;
    scanf("%d %d %c",&a,&b,&c);
    if(c=='+')printf("%d",a+b);
    else if(c=='-')printf("%d",a-b);
    else if(c=='*')printf("%ld",a*b);
    else if(c=='/'){
        if(b!=0)printf("%d",a/b);
        else printf("NO");
        }
    else if(c=='%'){
        if(b!=0)printf("%d",a/b);
        else printf("NO");

        }
    else printf("NO");
    return 0;
}