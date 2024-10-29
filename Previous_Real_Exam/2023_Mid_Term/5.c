#include <stdio.h>
#include <string.h>
struct voteinfo {
    char name[10];
    int score;
};
int main() {
    char one_voter[10000];
    int num_candi = 0;
    struct voteinfo my_info[20];
    while (strcmp(one_voter, "Ending") != 0) {
        gets(one_voter);
        char *the_name = strtok(one_voter, " ");
        while (the_name != NULL) {
            // printf("%s\n", the_name);
            int not_in = 1;
            for (int i = 0; i < num_candi; i++) {
                if (strcmp(the_name, my_info[i].name) == 0) {
                    my_info[i].score++;
                    not_in = 0;
                }
            }
            if (not_in) {
                strcpy(my_info[num_candi].name, the_name);
                my_info[num_candi].score = 1;
                num_candi++;
            }
            the_name = strtok(NULL, " ");
        }
    }
    int max_i=0;
    for (int i = 0; i < num_candi-1; i++) {
        if(my_info[i].score>my_info[max_i].score){
            max_i=i;
        }
    }
    printf("%s %d",my_info[max_i].name,my_info[max_i].score);
    return 0;
}