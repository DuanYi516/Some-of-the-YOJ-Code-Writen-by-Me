#include<stdio.h>
#include<string.h>
int havent_allocate(int *scheme,int psn,int book){
    for(int i=0;i<book;i++){
        if(psn==scheme[i])return 0;
    }
    return 1;
}
void allocate(int like[100][100], int book,int *scheme,int N){
    if(book==N){
        for(int i=0;i<N;i++){
            printf("%d ",scheme[i]);
        }
        printf("\n");
    }else{
        for(int psn=0;psn<N;psn++){
            if(like[book][psn]&&havent_allocate(scheme,psn,book)){
                scheme[book]=psn;
                allocate(like,book+1,scheme,N);
                scheme[book]=0;
            }
        }
    }
}
int main(){
    int N=5;  // scanf("%d",&N);
    const int like[100][100] ={
            {0, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 0, 1},
            {0, 0, 0, 1, 0},
            {0, 1, 0, 0, 1}
        };   
    // for(int book_preference=0;book_preference<N;book_preference++){
    //     for(int psn=0;psn<N;psn++){
    //         scanf("%d",&like[book_preference][psn]);
    //     }
    // }
    
    int scheme[101]={0};
    allocate(like,0,scheme,N);
    return 0;
}