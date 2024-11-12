#include<stdio.h>
struct line{
    int num;
    int index;
};
int main(){
    int n;scanf("%d",&n);
    struct line my_line[200];
    for(int i=0;i<n;i++){
        scanf("%d",&my_line[i].num);
        my_line[i].index=i;
    }
    
    for(int i=0;i<n;i++){
        int min_id=i;
        for(int j=i+1;j<n;j++){
            if(my_line[j].num<my_line[min_id].num){
                struct line temp;
                temp=my_line[i];
                my_line[i]=my_line[j];
                my_line[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)printf("%d ",my_line[i].index);
}
