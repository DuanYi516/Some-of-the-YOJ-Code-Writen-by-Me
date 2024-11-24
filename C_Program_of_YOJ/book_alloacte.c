#include<stdio.h>
#include<string.h>
int havent_allocate(char*scheme,int psn,int book){
    for(int i=0;i<book;i++){
        if(psn+'0'==scheme[i])return 0;
    }
    return 1;
}
void allocate(int like[100][100], int book,char*scheme,int N){
    if(book==N){
        puts(scheme);
    }else{
        for(int psn=0;psn<N;psn++){
            if(like[book][psn]&&havent_allocate(scheme,psn,book)){
                scheme[book]=psn+'0';
                allocate(like,book+1,scheme,N);
                scheme[book]='0';
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
    
    char scheme[101];
    for(int i=0;i<N;i++)strcat(scheme,"0");
    scheme[N]='\0';

    allocate(like,0,scheme,N);
    return 0;
}
// -----------------------------------------------------------------------------------------------
// #include <stdio.h>

// // show
// void show(int fenpei_book[N])
// {
//     printf("%d %d %d %d %d\n", //
//            fenpei_book[0], fenpei_book[1], fenpei_book[2], //
//            fenpei_book[3], fenpei_book[4]);
// }
// // check_so_far
// int check_so_far(int cur_person, int book, int fenpei_book[N])
// {
//     // 0号person, 和[]下标fenpei_book检查
//     // 1号person, 和[0]下标fenpei_book检查
//     // 2号person, 和[0 1]下标fenpei_book检查
//     // 3号person, 和[0 1 2 ]下标fenpei_book检查
//     // 4号person, 和[0 1 2 3]下标fenpei_book检查

//     int i;
//     for(i = 0; i <= cur_person - 1; i++)
//     {
//         int index = i;
//         int book_you = fenpei_book[index];
//         if(book_you == book)
//             return 1;//用过了
//     }

//     return 0;//没用过
// }
// // fenshu
// void fenshu(int cur_person, int fenpei_book[N], int like[N][N])
// {
//     int book;
//     for(book = 0; book <= 4; book++)
//     {
//         int xihuan_ma = like[cur_person][book];
//         if(xihuan_ma)
//         {
//             if(check_so_far(cur_person, book, fenpei_book) == 0)//没用过
//             {
//                 fenpei_book[cur_person] = book;

//                 if(cur_person == 4)
//                     show(fenpei_book);
//                 else
//                     fenshu(cur_person + 1, fenpei_book, like);
//             } // check so far
//         }     // xihuan ma
//     }         // for book
// };
// //main
// int main()
// {
//     // N个人（行）0，1，2，3，4
//     // 喜欢N本书（列）0，1，2，3，4

//     int like[N][N] = { 0, 0, 1, 1, 0,
//                        1, 1, 0, 0, 1,
//                        0, 1, 1, 0, 1,
//                        0, 0, 0, 1, 0,
//                        0, 1, 0, 0, 1
//                      };

//     int fenpei_book[N] = { -1, -1, -1, -1, -1 };

//     int cur_person = 0;
//     fenshu(cur_person, fenpei_book, like);

//     return 0;
// }
