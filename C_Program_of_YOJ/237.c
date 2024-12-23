#include <stdio.h>
#include <stdlib.h>
int max(int *stone, int n) {
    int mx = stone[0];
    for (int i = 1; i < n; i++) mx = (stone[i] > mx) ? stone[i] : mx;
    return mx;
}
int calc(int *stone, int N, int m0, int avg) {
    int m[N];
    m[0] = m0;
    for (int i = 1; i <= N - 2; i++) {
        int remain = 0;
        for (int j = 1; j <= i; j++) remain += stone[j];
        m[i] = m[0] - avg * i + remain;
    }
    m[N - 1] = m0 + avg - stone[0];
    int sum = 0;
    for(int i=0;i<N;i++) sum += abs(m[i]);
    return sum;
}
int main() {
    int n;
    int sum = 0;
    int stone[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stone[i]);
        sum += stone[i];
    }
    int avg = sum / n;
    int min_res = 1633370;
    for (int m0 = avg - max(stone, n); m0 < max(stone, n) - avg; m0++) {
        min_res = calc(stone, n, m0, avg) > min_res ? min_res : calc(stone, n, m0, avg);
    }
    printf("%d", min_res);
    return 0;
}