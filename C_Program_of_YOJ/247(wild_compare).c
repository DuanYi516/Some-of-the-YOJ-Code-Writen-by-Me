/*Wild号码是一个字符串，其仅包含数字或问号（如36?1?8）。一个数字W匹配一个Wild号码，当且仅当他们长度相同，
并且X中每一个非问号字符对应的数字与W中相同位置的数字相等，即一个问号符可以匹配任何一个一位数字 。
 举例来说，数字365198能匹配Wild号码36?1?8，而数字360199，361028，或36128则不能。 请你写一个程序，
 读入一个Wild号码X和一个数字W（输入保证W与X长度相等），并能与Wild号码X相匹配的若干数字中比数字W大的数有多少个。

输入格式
　　 输入包含若干组 ，每组成对出现,对于每组数据以如下格式：
        第一行表示号码X 　　
        第二行表示数字W 　　
        #表示输入结束 　　
    注意：输入wild号码的长度不超过10

输出格式
　　对应每组输出数据，输出n行，为n个整数，表示与Wild号码X相匹配的所有数字中比数字W大的数字个数。 */
#include <stdio.h>
#include <string.h>
int get_Q_loc(char *Wild) {
    for (int loc = 0; loc < strlen(Wild); loc++) {
        if (Wild[loc] == '?') return loc;
    }
    return -1;
}
void find(char *X, char *Wild, int *point_res_count) {
    int Q_loc = get_Q_loc(Wild);
    if (Q_loc == -1 && strcmp(Wild, X) > 0) {
        *point_res_count += 1;
    } else {
        for (int num = 0; num < 10; num++) {
            Wild[Q_loc] = num + '0';
            find(X, Wild, point_res_count);
            Wild[Q_loc] = '?';
        }
    }
}
int main() {
    char Wild[11], X[11];
    int result[1000], count = 0;
    while (1) {
        fgets(Wild,11,stdin);
        if (Wild[0] == '#') break;
        fgets(X,11,stdin);
        int res_count = 0;
        find(X, Wild, &res_count);
        result[count++] = res_count;
    }
    for (int i = 0; i < count; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}