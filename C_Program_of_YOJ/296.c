#include <stdio.h>
struct type_class_time {
    float time;
    int stu_num;
};
int main() {
    int m, k;  scanf("%d %d", &m, &k);
    struct type_class_time my_class[7][7];
    float res[49];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            my_class[i][j].stu_num = 0;
            res[7 * i + j] = (float)(j + 1) / 10 + i + 1;
        }
    }
    for (int i_stu = 0; i_stu < m; i_stu++) {
        int id, class_num;  scanf("%d %d", &id, &class_num);
        for (int c = 0; c < class_num; c++) {
            float time;  scanf("%f", &time);
            time += 0.01;
            int day = (int)time -1, jie = ((int)(10 * time)) % 10 -1;
            my_class[day][jie].time = time;
            my_class[day][jie].stu_num += 1;
        }
    }
    for (int start = 0; start < 49; start++) {
        int start_stu_num = 0;
        for (int cur = start + 1; cur < 49; cur++) {
            float s_time = res[start]+0.01, c_time = res[cur]+0.01;
            int s_day = (int)s_time - 1, s_jie = ((int)(10 * s_time)) % 10 - 1;
            int c_day = (int)c_time - 1, c_jie = ((int)(10 * c_time)) % 10 - 1;

            start_stu_num = my_class[s_day][s_jie].stu_num;

            if (my_class[c_day][c_jie].stu_num <  start_stu_num ||
               (my_class[c_day][c_jie].stu_num == start_stu_num && res[cur] < res[start])) {
                float tmp = res[cur];
                res[cur] = res[start];
                res[start] = tmp;
            }
        }
        if (start < k) printf("%.1f %d\n", res[start], start_stu_num);
    }
    return 0;
}