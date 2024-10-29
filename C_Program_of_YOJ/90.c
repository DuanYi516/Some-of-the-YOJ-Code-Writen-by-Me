#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    int id;
    int work[100];
    int req_work_num;
    int rank;
};
void swap(struct student s[], int n);
int max_i(struct student s[], int n);

int main() {
    int n;
    scanf("%d", &n); // n为要求题数
    int *require = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &require[i]);
        }
    int m, k;
    scanf("%d %d", &m, &k); // m为班级人数，k为前k名
    struct student class[100];
    for (int i = 0; i < m; i++) {
        scanf("%d", &class[i].id);
        int p;
        scanf("%d", &p); // p为该同学的题数
        class[i].req_work_num = 0;
        for (int j = 0; j < p; j++) {
            scanf("%d", &class[i].work[j]);
            for (int k = 0; k < n; k++) {
                if (class[i].work[j] == require[k]) {
                    class[i].req_work_num++;
                }
            }
        }
    }
    swap(class, m);
    int rank = 1;
    for (int i = 0; i < m - 1; i++) {
        class[i].rank = rank;
        if (class[i].req_work_num != class[i + 1].req_work_num) {
            rank++;
        }
    }
    class[m - 1].rank = rank;

    for (int i = 0; class[i].rank <= k; i++) {
        printf("%d ", class[i].id);
    }
    return 0;
}

void swap(struct student stu[], int n) {
    int id_min;
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (stu[i].req_work_num < stu[i + 1].req_work_num)
            flag += 1;
    } // 判断是否全部升序
    if (flag != n - 1) {
        id_min = max_i(stu, n);
        struct student temp = stu[0];
        stu[0] = stu[id_min];
        stu[id_min] = temp; // 以上4行是在交换当前数组的首项与最小项
        swap(stu + 1, n - 1);
    }
}
int max_i(struct student stu[], int n) {
    int max_i = 0;
    for (int i = 1; i < n; i++) {
        if (stu[i].req_work_num > stu[max_i].req_work_num ||
            (stu[i].req_work_num == stu[max_i].req_work_num &&
             stu[i].id < stu[max_i].id)) {
            max_i = i;
        }
        // else if((stu[i].req_work_num=stu[max_i].req_work_num)&&(stu[i].id<stu[max_i].id)){max_i=i;}
    } // 换成“s[i]>s[max_i]”就是从大到小
    return max_i;
}