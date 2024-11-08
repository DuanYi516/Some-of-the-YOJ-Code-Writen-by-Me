#include <stdio.h>
int is_bad(int col, int row, int image[100][100][3]) {
    return image[col][row][0]+image[col][row][1]+image[col][row][1]==0;
}
int main() {
    // int n, m;scanf("%d %d", &n, &m);
    // int image[100][100][3];
    // for (int row = 0; row < n; row++) {
    //     for (int col = 0; col < m; col++) {
    //         char r, g, b, nul;
    //         scanf("%c%c%d%c", &r, &nul, &image[row][col][0], &nul);
    //         scanf("%c%c%d%c", &g, &nul, &image[row][col][1], &nul);
    //         scanf("%c%c%d%c", &b, &nul, &image[row][col][2], &nul);
    //     }
    // }
    int n = 5, m = 5;
    int image[100][100][3] = {
        {{10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {200, 255, 255}, {10, 20, 30}},
        {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {200, 255, 255}},
        {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 20, 30}},
        {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 20, 30}},
        {{10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {10, 20, 30}}};

    int ROUND = (n > m) ? n : m;
    for (int i = 0; i < ROUND; i++) {
        int copy_image[100][100][3];
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < m; row++) {
                for (int c = 0; c < 3; c++) {
                    copy_image[col][row][c] = image[col][row][c];
                }
            }
        }
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < m; row++) {
                if (is_bad(col, row, copy_image)) {
                    int u = (col - 1 >= 0) && (1 - is_bad(col - 1, row, copy_image));
                    int d = (col + 1 < n ) && (1 - is_bad(col + 1, row, copy_image));
                    int l = (row - 1 >= 0) && (1 - is_bad(col, row - 1, copy_image));
                    int r = (row + 1 < m ) && (1 - is_bad(col, row + 1, copy_image));
                    if (u + d + l + r != 0) {
                        for (int c = 0; c < 3; c++) {                       
                            int son = u * copy_image[col - 1][row][c] +
                                      d * copy_image[col + 1][row][c] +
                                      l * copy_image[col][row - 1][c] +
                                      r * copy_image[col][row + 1][c];
                            int mom = u + d + l + r;
                            if (son % mom == 0) {
                                image[col][row][c] = son / mom;
                            } else {
                                image[col][row][c] = 1 + son / mom;
                            }
                        }
                    }
                } // 这个坏点处理完成
            }
        } // 本轮处理完成 
    }

    for (int col = 0; col < n; col++) {
        for (int row = 0; row < m; row++) {
            printf("R %d G %d B %d ", image[col][row][0], image[col][row][1], image[col][row][2]);
        }
        printf("\n");
    }
    return 0;
}