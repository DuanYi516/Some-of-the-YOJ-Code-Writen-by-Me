/*题目：输入一个字符串，输入一个整数N。
    对字符串进行N次轮转，然后输出。
    轮转的意思是，把字符串的第二个字符到最后一个字符，都往前挪一个字符，原来的第一个字符放到末尾。
             比如abcdef，轮转一次的效果为bcdefa。
 

输入、输出描述与样例：
比如输入aaabbbcccddd 1
输出aabbbcccddda
*/
#include<stdio.h>
#include<string.h>
void swap(char string[1000],int len){
    char copy_str[1000];
    for(int i=0;i<=len;i++){copy_str[i]=string[i];}
    for(int i=0;i<len-1;i++){
        string[i]=copy_str[i+1];
    }
    string[len-1]=copy_str[0];
}
int main(){
    char str[1000];scanf("%s",str);
    int N;scanf("%d",&N);
    int len=strlen(str);
    for(int i=0;i<N;i++){
        swap(str,len);
    }
    puts(str);
}