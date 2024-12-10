#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct type_info {
    int num;
    int w;
    int is_not_aban;
};
int is_sushu(long long int num){
    int is_su = 1;
    for (int div = 2; div <= sqrt(num); div++) {
        if (num % div == 0) {
            is_su = 0;
            break;
        }
    }
    return is_su;
}
long long int find(long long int n, int k) {
    if (is_sushu(n)) return 1;
    long long int n_copy = n;
    struct type_info my_info[10];
    int count = 0;
    int previos_num=1;
    while (n != 1){
        int num = previos_num + 1;
        for (; num < n; num++) {
            if(is_sushu(num)) {
                previos_num = num;
                break;
            }
        }
        if (n % num == 0) {
            my_info[count].w = 0;
            my_info[count].num = num;
            while (n % num == 0) {
                my_info[count].w++;
                n /= num;
            }
            if (my_info[count].w < k)  my_info[count].is_not_aban = 0;               
            else  my_info[count].is_not_aban = 1;
            count++;
        }
        
    }
    int sum = 0;
    for (int i = 0; i < count ; i++) sum += my_info[i].is_not_aban;
    if (sum == 0) return 1;
    else if (sum == count) return n_copy;
    else {
        int res = 1;
        for (int i = 0; i < count; i++) {
            if (my_info[i].is_not_aban) {
                for (int time = 0; time < my_info[i].w; time++) {
                    res *= my_info[i].num;
                }
            }
        }
        return res;
    }
}
int main() {
    long long int qs;
    scanf("%lld", &qs);
    long long int *res_info = malloc(qs * sizeof(long long int));
    for (int q = 0; q < qs; q++) {
        long long int n;
        int k;
        scanf("%lld %d", &n, &k);
        res_info[q] = find(n, k);
    }
    for (int q = 0; q < qs; q++) printf("%lld\n", res_info[q]);
    free(res_info);
    return 0;
}