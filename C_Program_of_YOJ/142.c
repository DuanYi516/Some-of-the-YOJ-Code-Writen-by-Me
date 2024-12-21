#include <stdio.h>
int judge(int ruleSize, int rule[], int base_row[], int cur_row[], int n) {
    for (int i = 0; i < ruleSize; i++) {
        if (base_row[rule[i] - 1] < cur_row[rule[i] - 1]) return 0;
        if (base_row[rule[i] - 1] > cur_row[rule[i] - 1]) return 1;
    }
    return (base_row[0] > cur_row[0]) ? 1 : 0;
}
void swap(int res[], int m, int base_i, int cur_i) {
    int temp = res[base_i];
    res[base_i] = res[cur_i];
    res[cur_i] = temp;
}
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int ruleSize; scanf("%d", &ruleSize);
    int rule[100];
    for (int i = 0; i < ruleSize; i++) scanf("%d", &rule[i]);
    int form[100][100], res[100];
    for (int row = 0; row < m; row++) {
        res[row] = row;
        for (int col = 0; col < n; col++) {
            scanf("%d", &form[row][col]);
        }
    }
    for (int row = 0; row < m; row += 1) {
        for (int cur = row + 1; cur < m; cur++) {
            if (judge(ruleSize, rule, form[res[row]], form[cur], n)) {
                swap(res, m, row, cur);
            }
        }
        for (int col = 0; col < n; col++) printf("%d ", form[res[row]][col]);
        printf("\n");
    }
    return 0;
}