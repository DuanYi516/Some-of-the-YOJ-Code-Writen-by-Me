#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int tree[100][100];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i + 1; j++)
            scanf("%d", &tree[i][j]);
    for (int floor = N - 1; floor >= 0; floor--)
        for (int fruit = 0; fruit < floor; fruit++)
            tree[floor - 1][fruit] += (tree[floor][fruit] > tree[floor][fruit + 1]) ? tree[floor][fruit] : tree[floor][fruit + 1];
    printf("%d", tree[0][0]);
    return 0;
}