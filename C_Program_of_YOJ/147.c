#include <stdio.h>
struct type_alloc_info {
    int may_alloc[8];
    int may_count;
};
int room[8] = {120, 40, 85, 50, 100, 140, 70, 100};
static struct type_alloc_info alloc_info[4];

void print_alloc(int class, int final_alloc_info[4], int* p_count) {
    if (class == 4) {
        printf("%d %d %d %d\n", final_alloc_info[0], final_alloc_info[1],\
                                final_alloc_info[2], final_alloc_info[3]);
        (*p_count)++;
        int final_alloc_info[4] = {0, 0, 0, 0};
    } else {
        for (int i = 0; i < alloc_info[class].may_count; i++) {
            int flag = 0;
            for (int c = 0; c < class; c++) { // 检查是否已经排过课
                if (alloc_info[class].may_alloc[i] != final_alloc_info[c]) flag++;
            } 
            if (flag == class) { // 若没有
                final_alloc_info[class] = alloc_info[class].may_alloc[i];
                class ++;
                print_alloc(class, final_alloc_info, p_count); // 递归
                class --;
                final_alloc_info[class] = 0;
            }
        }
    }
}

void find_alloc(int class_info[4]) {
    for (int class = 0; class < 4; class ++) {
        int may_count = 0;
        for (int r = 0; r < 8; r++) {
            if (room[r] >= class_info[class]) {
                alloc_info[class].may_alloc[may_count++] = r + 1;
            }
        }
        alloc_info[class].may_count = may_count;
        if (may_count == 0) {
            printf("-1");
            return;
        }
    }
    int count = 0;
    int final_alloc[4] = {0, 0, 0, 0};
    print_alloc(0, final_alloc, &count);
    if (count == 0) printf("-1");
    return;
}

int main() {
    int class_info[4]; //={100,100,120,120};
    for (int i = 0; i < 4; i++) scanf("%d", &class_info[i]);
    find_alloc(class_info);
    return 0;
}