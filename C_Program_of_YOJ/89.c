#include <stdio.h>
struct type_form {
    int baseline;
    double rate;
};

int main() {
    int N;scanf("%d", &N);
    struct type_form crition[100];
    int copy_baseline[100];
    
    for (int i = 0; i < N; i++) {
        scanf("%d %lf", &crition[i].baseline, &crition[i].rate);
        copy_baseline[i]=crition[i].baseline;
        crition[i].baseline -= copy_baseline[i - 1];
    }
    int rev;
    scanf("%d", &rev);
    
    if (rev < 0) {
        printf("NO");
    } 
    else {
        double prize = 0;
        for (int i = 0; i < N; i++) {
            if (rev > crition[i].baseline && i != N-1) {
                rev -= crition[i].baseline;
                prize += crition[i].baseline * crition[i].rate;
            } 
            else {
                prize += rev * crition[i].rate;
                break;
            }
        }
        printf("%.2lf", prize);
    }
    return 0;
}