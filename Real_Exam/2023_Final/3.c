#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct point {
    int id;
    int x, y;
};
struct type_line {
    struct point p1;
    struct point p2;
    int count;
};

int isBelong(struct type_line my_line, struct point my_point) {
    int t1 = (my_point.y - my_line.p1.y) * (my_line.p2.x - my_line.p1.x);
    int t2 = (my_point.x - my_line.p1.x) * (my_line.p2.y - my_line.p1.y);
    return -1e-6 < t1 - t2 && t1 - t2 < 1e-6;
}

int main() {
    int pnt_num; scanf("%d", &pnt_num);
    struct point *point_set = malloc(pnt_num * sizeof(struct point));
    // if (point_set == NULL) {
    //     fprintf(stderr, "Memory allocation failed\n");
    //     return 1;
    // }
    // 读取输入并初始化结构体
    for (int i = 0; i < pnt_num; i++) {
        point_set[i].id = i;
        scanf("%d %d", &point_set[i].x, &point_set[i].y);
    }
    struct type_line *line_set = malloc(pnt_num * (pnt_num - 1) / 2 * sizeof(struct type_line));
    int line_num = 0;
    for (int i = 0; i < pnt_num; i++) {
        for (int j = i + 1; j < pnt_num; j++) {
            line_set[line_num].p1 = point_set[i]; // 传递整个结构体，包括 id
            line_set[line_num].p2 = point_set[j]; // 传递整个结构体，包括 id
            line_set[line_num].count = 2;

            for (int k = 0; k < pnt_num; k++) {
                if (k == i || k == j) continue;
                if (isBelong(line_set[line_num], point_set[k])) line_set[line_num].count++;
            }
            line_num++;
        }
    }
    int max_i = 0;
    for (int strt = 0; strt < line_num; strt++) {
        max_i = (line_set[strt].count > line_set[max_i].count) ? strt : max_i;
    }
    printf("%d %d", line_set[max_i].p1.id, line_set[max_i].p2.id);
    free(line_set);
    free(point_set);
    return 0;
}