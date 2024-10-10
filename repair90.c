#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct student{
    int id;
    int work[100];
    int req_work_num;
    int rank;
};
void swap(struct student s[],int n);
int max_i(struct student s[],int n);

int main(){
    FILE *file = fopen("error_90_ck1.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    int n;fscanf(file,"%d",&n);   //n为要求题数
    int *require=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)fscanf(file,"%d",&require[i]);
    int m,k;fscanf(file,"%d %d",&m,&k);  //m为班级人数，k为前k名
    struct student class[100];
    for(int i=0;i<m;i++){
        fscanf(file,"%d",&class[i].id);
        int p;fscanf(file,"%d",&p);//p为该同学的题数
        class[i].req_work_num=0;
        for(int j=0;j<p;j++){
            fscanf(file,"%d",&class[i].work[j]);
            for(int k=0;k<n;k++){
                if(class[i].work[j]==require[k]){
                    class[i].req_work_num++;
                }
            }
        }
    }
    swap(class,m);
    int rank=1;
    for(int i=0;i<m-1;i++){
        class[i].rank=rank;
        if(class[i].req_work_num!=class[i+1].req_work_num){
            rank++;
        }
    }
    class[m-1].rank=rank;
    
    for(int i=0;class[i].rank<=k;i++){
        printf("%d ",class[i].id);
    }
    // for(int i=k;i<m-1;i++){
    //     if(class[i].req_work_num==class[k-1].req_work_num)printf("%d ",class[i].id);
    // }
    return 0;
}



void swap(struct student stu[],int n){
    int id_min;
    int flag=0;
    for(int i=0;i<n-1;i++){if(stu[i].req_work_num<stu[i+1].req_work_num)flag+=1;} //判断是否全部升序
    if(flag!=n-1){
        id_min=max_i(stu,n);
        struct student temp=stu[0];
        stu[0]=stu[id_min];
        stu[id_min]=temp;  // 以上4行是在交换当前数组的首项与最小项
        swap(stu+1,n-1);
    }
}
int max_i(struct student stu[],int n){
    int max_i=0;
    for(int i=1;i<n;i++){
        if(stu[i].req_work_num>stu[max_i].req_work_num
            ||  (stu[i].req_work_num==stu[max_i].req_work_num&&
                stu[i].id<stu[max_i].id
                )
            ){max_i=i;}
        //else if((stu[i].req_work_num=stu[max_i].req_work_num)&&(stu[i].id<stu[max_i].id)){max_i=i;}
    } //换成“s[i]>s[max_i]”就是从大到小
    return max_i;
}

// void DubbleSort(struct student stu[],int N){
// 	for(int i = 0; i < N-1 ; i++){
// 		for(int j = 0; j < N-i-1 ;j++){
// 			if(
//                 stu[j].req_work_num<stu[j+1].req_work_num
//                 ||  (stu[j].req_work_num=stu[j+1].req_work_num&&
//                      stu[j].id>stu[j+1].id
//                     )
//                 ){    //比较成绩的大小
// 				struct student temp = stu[j+1];    //成绩大的交换所在的数组元素
// 				stu[j+1] = stu[j];
// 				stu[j] = temp;
// 			}
// 		}
// 	}
// }