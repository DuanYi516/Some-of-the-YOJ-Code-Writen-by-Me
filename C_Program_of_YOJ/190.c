//65-90up,97-122down
#include<stdio.h>
#include<string.h>
struct letter_count{
    int lt;
    int ct;
};
int min_i(int s[],int n);
void swap(struct letter_count my_ltct[250],int len_set,int his,int L);
int main(){
    char s[250];get(s);
    int len=strlen(s);
    int s2int[250];
    int len_set=0;
    struct letter_count my_ltct[250]={0,0};
    for(int i=0;i<len;i++){
        if(s[i]<97){
            s2int[i]=s[i]+32;
        }
        else{s2int[i]=s[i]+0;}
        int not_in=1;
        for(int j=0;j<len_set;j++){
            if(s2int[i]==my_ltct[j].lt){
                not_in=0;
                my_ltct[j].ct++;
                break;
            }
        }
        if(not_in){
            my_ltct[len_set].lt=s2int[i];
            my_ltct[len_set].ct=1;
            len_set++;
        }
    }
    swap(my_ltct,len_set,0,len_set);
    for(int i=0;i<len_set;i++){
        printf("%c %d\n",my_ltct[i].lt,my_ltct[i].ct);
    }
}
void swap(struct letter_count my_ltct[250],int len_set,int his,int L){
    
    //for(int i=0;i<len_set-1;i++){if(my_ltct[i].ct<=my_ltct[i+1].ct)flag+=1;} //判断是否全部升序
    if(his!=L-1){
        int id_min=0;
        for(int j=1;j<len_set;j++){
            int t1=my_ltct[j].ct,t2=my_ltct[id_min].ct;
            if(my_ltct[j].ct>my_ltct[id_min].ct||
            (my_ltct[j].ct==my_ltct[id_min].ct&&my_ltct[j].lt<my_ltct[id_min].lt)
            ){
                id_min=j;
            }
        }
        struct letter_count temp=my_ltct[0];
        my_ltct[0]=my_ltct[id_min];
        my_ltct[id_min]=temp;  // 以上4行是在交换当前数组的首项与最小项
        swap(my_ltct+1,len_set-1,his+1,L);
    }
}
int min_i(int s[],int n){
    int min_i=0;
    for(int i=1;i<n;i++){if(s[i]>s[min_i]){min_i=i;}} //换成“s[i]<s[min_i]”就是从大到小
    return min_i;
}