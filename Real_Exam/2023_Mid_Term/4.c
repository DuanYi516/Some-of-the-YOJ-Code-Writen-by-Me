#include <stdio.h>
int find(int n, int m){
    for (int day = 0; day < m; day++){
        if ((n - 1) % m)return 0;
        n = (n - 1) * (m - 1) / m;
    }
    if (n % m==0)return 1;
    else return 0;
}
void f(int n){
    for (int m = 2; m < 10; m++){
        if (find(n, m)){
            printf("%d\n", m);
            return;
        }
    }
    printf("no solution\n");
    return;
}

int main(){
    int input_list[20];
    int in = 1;
    int i = 0;
    while (in > 0){
        scanf("%d", &input_list[i]);
        in = input_list[i];
        i++;
    }
    for (int j = 0; j < i - 1; j++)f(input_list[j]);
    return 0;
}
