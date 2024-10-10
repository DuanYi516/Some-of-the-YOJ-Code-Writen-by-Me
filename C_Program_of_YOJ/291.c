// #include <stdio.h>
// #include <string.h>
// char plus(char a[],char b[],int len_a,int len_b);
// char minus(char a[],char b[],int len_a,int len_b);
// int main(){
//     char operate='+',enter;
//     // scanf("%c%c",&operate,&enter);
//     // char a[1000],b[1000];
//     char a[1000]="315829878919148126n",b[1000]="38310545445462588n";
//     char sign_a,sign_b;
//     int len_a,len_b;
//     // for(int i=0;i<1000;i++){scanf("%c",&a[i]);if(a[i]=='\n')break;}
//     // for(int i=0;i<1000;i++){scanf("%c",&b[i]);if(b[i]=='\n')break;}
//     if(a[0]=='-'){
//         sign_a=a[0];
//         len_a=strlen(a)-2;
//         for(int i=0;i<len_a;i++)a[i]=a[i+1];
//         a[len_a] = '\0';
//     }
//     else{len_a=strlen(a)-1;sign_a='+';}
//     if(b[0]=='-'){
//         sign_b=b[0];
//         len_b=strlen(b)-2;
//         for(int i=0;i<len_b;i++)b[i]=b[i+1];
//         b[len_b] = '\0';
//     }
//     else{len_b=strlen(b)-1;sign_b='+';}
//     int test_op=44-(int)operate;
//     int test_a=44-(int)sign_a;
//     int test_b=44-(int)sign_b;
//     // printf("%d,%f",test_a*test_b*test_op,test_a*test_b*test_op);
//     if(test_a*test_b*test_op==1){
//         if(test_b*test_op==-1)printf("-");
//         plus(a,b,len_a,len_b);
//         }
    
//     else{
//         int judge=1;
//         if(len_a>=len_b&&a[0]>=b[0]&&a[1]>=b[1])judge=-1;
//         if(test_b*test_op==-1&&judge==1)printf("-");
//         minus(a,b,len_a,len_b);
//         }
//     // printf("%llu",strlen(a));
//     // if(a[0]=='-'){
//     //     sign_a='+';
//     // }
//     return 0;
// }
// char plus(char a[],char b[],int len_a,int len_b){
//     int max_len=(len_a>len_b)?len_a+1:1+len_b;
//     int num_a[max_len],num_b[max_len];
//     for(int i=0;i<max_len;i++){
//         if(i<len_a)num_a[i]=(int)a[len_a-i-1]-48;
//         else num_a[i]=0;
//         if(i<len_b)num_b[i]=(int)b[len_b-i-1]-48;
//         else num_b[i]=0;
//         }
//     int ahead[max_len];
//     int res[max_len];
//     for(int i=0;i<max_len;i++){
//         ahead[0]=0;
//         res[i]=num_a[i]+num_b[i]+ahead[i];
//         if(res[i]>9){
//             ahead[i+1]=1;
//             res[i]-=10;
//         }
//         else ahead[i+1]=0;
//     }//354 140 424 364 610 714
//     char result[max_len];
//     for(int i=0;i<max_len;i++){
//         if(i==max_len-1&&res[i]==0){result[i]='\0';break;}
//         result[i]=res[i]+48;}
//     // printf("%llu\n",strlen(result));
//     for(int i=0;i<strlen(result)/2;i++){
//         char temp;
//         temp=result[strlen(result)-i-1];
//         result[strlen(result)-i-1]=result[i];
//         result[i]=temp;
//         }
//     printf("%s",result);
// }
// char minus(char a[],char b[],int len_a,int len_b){
//     int max_len=(len_a>len_b)?len_a:len_b;
//     int num_a[max_len],num_b[max_len];
//     for(int i=0;i<max_len;i++){
//         if(i<len_a)num_a[i]=(int)a[len_a-i-1]-48;
//         else num_a[i]=0;
//         if(i<len_b)num_b[i]=(int)b[len_b-i-1]-48;
//         else num_b[i]=0;
//     }
//     int *max,*min;
//     if(len_a>=len_b&&num_a[max_len]>num_b[max_len]){max=num_a;min=num_b;}
//     else {max=num_b;min=num_a;}
//     // for(int i=0;i<max_len;i++)printf("%d",*(max+i));
//     // printf("\n");
//     // for(int i=0;i<max_len;i++)printf("%d",*(min+i));
//     int lend[max_len];
//     int res[max_len];
//     for(int i=0;i<max_len;i++){
//         lend[0]=0;
//         res[i]=*(max+i)-*(min+i)-lend[i];
//         if(res[i]<0){
//             lend[i+1]=1;
//             res[i]+=10;
//         }
//         else lend[i+1]=0;
//     }
//     char result[max_len];
//     for(int i=0;i<max_len;i++){
//         if(i==max_len-1&&res[i]==0)break;
//         result[i]=res[i]+48;}
//     // printf("%llu\n",strlen(result));
//     for(int i=0;i<strlen(result)/2;i++){
//         char temp;
//         temp=result[strlen(result)-i-1];
//         result[strlen(result)-i-1]=result[i];
//         result[i]=temp;
//         }
//     printf("%s",result);
// }
// // int main(){
// //     char a[5]="yes";
// //     for(int i=0;i<3;i++)printf("%c",a[i]);
// // }
#include <stdio.h>
#include <string.h>
char plus(char a[],char b[],int len_a,int len_b);
char minus(char a[],char b[],int len_a,int len_b);
int main(){
    char operate,enter;
    scanf("%c%c",&operate,&enter);
    char a[1000],b[1000];
    char sign_a,sign_b;
    int len_a,len_b;
    for(int i=0;a[i]!='\n';i++){scanf("%c",&a[i]);if(a[i]=='\n')break;}
    for(int i=0;b[i]!='\n';i++){scanf("%c",&b[i]);if(b[i]=='\n')break;}
    for(int i=0;i<1000;i++){
        if(b[i]=='\n'){
            b[i]=='\0';
            break;
        }
    }
    printf("%s",b);
    // scanf("%c",&enter);
    if(a[0]=='-'){
        sign_a=a[0];
        len_a=strlen(a)-2;
        for(int i=0;i<len_a;i++)a[i]=a[i+1];
        a[len_a] = '\0';
    }
    else{len_a=strlen(a)-1;sign_a='+';a[len_a] = '\0';}
    if(b[0]=='-'){
        sign_b=b[0];
        len_b=strlen(b)-2;
        for(int i=0;i<len_b;i++)b[i]=b[i+1];
        b[len_b] = '\0';
    }
    else{len_b=strlen(b)-1;sign_b='+';b[len_b] = '\0';}
    int test_op=44-(int)operate;
    int test_a=44-(int)sign_a;
    int test_b=44-(int)sign_b;
    if(test_a*test_b*test_op==1){
        if(test_b*test_op==-1)printf("-");
        plus(a,b,len_a,len_b);
        }
    else{
        int judge=1;
        if(len_a>=len_b&&a[0]>=b[0]&&a[1]>=b[1])judge=-1;
        if(test_b*test_op==-1&&judge==1)printf("-");
        minus(a,b,len_a,len_b);
        }
    return 0;
}
char plus(char a[],char b[],int len_a,int len_b){
    int max_len=(len_a>len_b)?len_a+1:1+len_b;
    int num_a[max_len],num_b[max_len];
    for(int i=0;i<max_len;i++){
        if(i<len_a)num_a[i]=(int)a[len_a-i-1]-48;
        else num_a[i]=0;
        if(i<len_b)num_b[i]=(int)b[len_b-i-1]-48;
        else num_b[i]=0;
        }
    int ahead[max_len];
    int res[max_len];
    for(int i=0;i<max_len;i++){
        ahead[0]=0;
        res[i]=num_a[i]+num_b[i]+ahead[i];
        if(res[i]>9){
            ahead[i+1]=1;
            res[i]-=10;
        }
        else ahead[i+1]=0;
    }//354 140 424 364 610 714
    char result[max_len];
    for(int i=0;i<max_len;i++){
        if(i==max_len-1&&res[i]==0){result[i]='\0';break;}
        result[i]=res[i]+48;}
    for(int i=0;i<strlen(result)/2;i++){
        char temp;
        temp=result[strlen(result)-i-1];
        result[strlen(result)-i-1]=result[i];
        result[i]=temp;
        }
    printf("%s",result);
}
char minus(char a[],char b[],int len_a,int len_b){
    int max_len=(len_a>len_b)?len_a:len_b;
    int num_a[max_len],num_b[max_len];
    for(int i=0;i<max_len;i++){
        if(i<len_a)num_a[i]=(int)a[len_a-i-1]-48;
        else num_a[i]=0;
        if(i<len_b)num_b[i]=(int)b[len_b-i-1]-48;
        else num_b[i]=0;
    }
    int *max,*min;
    if(len_a>=len_b&&num_a[max_len]>num_b[max_len]){max=num_a;min=num_b;}
    else {max=num_b;min=num_a;}
    int lend[max_len];
    int res[max_len];
    for(int i=0;i<max_len;i++){
        lend[0]=0;
        res[i]=*(max+i)-*(min+i)-lend[i];
        if(res[i]<0){
            lend[i+1]=1;
            res[i]+=10;
        }
        else lend[i+1]=0;
    }
    char result[max_len];
    for(int i=0;i<max_len;i++){
        if(i==max_len-1&&res[i]==0)break;
        result[i]=res[i]+48;}
    for(int i=0;i<strlen(result)/2;i++){
        char temp;
        temp=result[strlen(result)-i-1];
        result[strlen(result)-i-1]=result[i];
        result[i]=temp;
        }
    printf("%s",result);
}
//31582 98789 19148 126,38310 54544 54625 88