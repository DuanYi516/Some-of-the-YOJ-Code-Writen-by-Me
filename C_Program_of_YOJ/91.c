#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*第2行，两个整数n和k，用空格隔开。表示有n首乐曲，1≤n≤100，查找最相似的k(1≤k≤n)首乐曲。

第3行到n+2行，表示编号从0到n-1的n首乐曲。每行一个正整数ni(1≤ni≤100), 
表示该乐曲长度，后面ni个整数，每个整数在[0,255]内，表示一个频率。*/

int cmp(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);}
void to_vector(int song[], int len_song, int v[16]) {
    int direction = 0;
    for (int i = 0; i < 100; i++) {
        if (song[i] < 256 && song[i] > 0) {
            direction = song[i] / 16;
            if (direction < 16)
                v[direction] += 1;
        }
    }
}
float calc_sim(int *v, int *vi) {
    int d = 0;
    for (int i = 1; i < 16; i++) {d += (v[i] - vi[i]) * (v[i] - vi[i]);}
    return sqrt(d);
}
int main() {
    int i, j;
    int len_song;scanf("%d ", &len_song);
    int *song = (int *)malloc(len_song * sizeof(int));
    for (int i = 0; i < len_song; i++) { scanf("%d ", &song[i]);}

    int n, k;
    float score;
    scanf("%d %d", &n, &k);
    float result[n], origin_result[n];

    int v[16] = {0};
    to_vector(song, len_song, v);

    for (int i = 0; i < n; i++) {
        int len_si;
        scanf("%d ", &len_si);
        int *ku_song = (int *)malloc(len_si * sizeof(int));
        for (int j = 0; j < len_si; j++) {scanf("%d ", &ku_song[j]);}

        int vi[16] = {0};
        to_vector(ku_song, len_si, vi);
        score = calc_sim(v, vi);
        result[i] = score;
        free(ku_song);
    }

    for (int i = 0; i < n; i++) {
        origin_result[i] = result[i];
    }
    qsort(result, n, sizeof(float), cmp);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i] == origin_result[j])printf("%d ", i);}
    }
    return 0;
}
