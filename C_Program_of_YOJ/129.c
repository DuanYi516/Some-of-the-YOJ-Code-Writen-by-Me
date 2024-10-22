# include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
int anum_bs_10(char *al_num,char*al_lgg);
char *ten_to_tar(int base10,char *tar_lgg);
int main(){
    int N=1;scanf("%d",&N);
    char record[100][3];
    for (int i = 0; i < N; i++){
        char al_num[1000000];scanf("%s",al_num);
        char al_lgg[94];scanf("%s",al_lgg);
        char tar_lgg[94];scanf("%s",tar_lgg);
        int bs_a=strlen(al_lgg);
        int bs_tar=strlen(tar_lgg);

        int base10=anum_bs_10(al_num,al_lgg);
        char *result=ten_to_tar(base10,tar_lgg);
        printf("Case #%d:%s",i+1,result);
        ;
    }
    return 0;
}
char *ten_to_tar(int base10, char *tar_lgg) {
    int base = strlen(tar_lgg); // 计算进制的基数
    char *res = (char *)malloc(100 * sizeof(char)); // 动态分配内存
    if (res == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int index = 0;
    do {
        res[index++] = tar_lgg[base10 % base];//printf("%c",tar_lgg[base10 % base]);
        base10 /= base;
    } while (base10 > 0);

    res[index] = '\0';
    // 反转字符串
    for (int i = 0; i < index / 2; i++) {
        char temp = res[i];
        res[i] = res[index - i - 1];
        res[index - i - 1] = temp;
    }

    return res;
}
int anum_bs_10(char *al_num,char*al_lgg){
    int bs_a=strlen(al_lgg);
    int len_num=strlen(al_num);
    int res=0;
    for(int i=0;i<len_num;i++){
        for(int n=0;n<bs_a;n++){
            if(al_num[i]==al_lgg[n]){
                res+=(int)pow(bs_a,len_num-i-1)*n;
            }
        }
    }
    return res;
}