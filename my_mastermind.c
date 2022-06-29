#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// string comparing function: (1) - means similar, (0) - means dissimilar
int str_compare(char* param_1, char* param_2) {
    int len1=0, len2=0;
    int similar = 1;
    while (param_1[len1]!='\0') {
        len1++;
    }
    while (param_2[len2]!='\0') {
        len2++;
    }
    if (len1==len2) {
        for (int i=0; i<len1; i++) {
            if (param_1[i]!=param_2[i]) {
                similar = 0;
                break;
            }
        }
    }
    else {
        similar = 0;
    }
    return similar;
}

void input_ct(int argc, char *argv[], int *code, int *t) {
    char *c_flag = "-c"; 
    char *t_flag = "-t";
    int c_active = 0, t_active = 0;
    int c_found = 0, t_found = 0;
    char *code_str, *t_str;

    for (int i=0; i<argc; i++) {
        if (str_compare(argv[i], c_flag) && c_active==0 && c_found==0) {
            c_active = 1;
            printf("Tema_c");
        }
        else if (str_compare(argv[i], t_flag) && t_active==0 && t_found==0) {
            t_active = 1;
            printf("Tema_t");
        }
        else if (c_active==1 && c_found==0) {
            c_found = 1;
            code_str = argv[i];
        }
        else if (t_active==1 && t_found==0) {
            t_found = 1;
            t_str = argv[i];
        }
        printf("%d: %s\n", i, argv[i]);
    }
    *code = atoi(code_str);
    *t = atoi(t_str);

    printf("Code: %s\n",code_str);
    printf("Attemps: %s\n",t_str);
}

int main(int argc, char *argv[]) {
    
    int code, t;
    input_ct(argc,argv, &code, &t);
    printf("%d\n", code);
    printf("%d\n", t);
    return 0;
}