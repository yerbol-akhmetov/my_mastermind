#include "source.h"

char* my_strcpy(char* param_1, char* param_2) {
    int i = 0;
    while (param_2[i]!='\0') {
        param_1[i] = param_2[i];
    }
    return param_1;
}

int my_strlen(char* param_1) {
    int count = 0;
    while (param_1[count]!='\0') {
        count += 1;
    }
    return count;
}
int my_atoi(char* param_1) {
    int num = 0;
    for (int i=0; param_1[i]!='\0'; i++) {
        num = num*10 + (param_1[i] - '0');
    }
    return num;
}

int is_valid_code(char* code) {
    if (my_strlen(code)!=4) {
        printf("Error: length should be 4!");
        return 1;
    }
    if (is_number(code)==1) {
        printf("Error: digits must be entered!");
        return 1;
    }
    return 0;
}
int is_number(char* str) {
    for (int i=0; str[i]!='\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '7')) {
            return 1;
        }
        
    }
    return 0;
}

t_game_data* parse_params(t_game_data* game_data, int argc, char** argv) {
    int i = 0;
    while (i+1 < argc) {
        if (my_strlen(argv[i])==2 && argv[i][0]=='-') {
            if (argv[i][1]=='c') {
                char* code = argv[i+1];
                if(is_valid_code(code)!=0) {
                    break;
                }
                my_strcpy(game_data->secret_code, code);
            }
            else if (argv[i][1]=='t') {
                if (is_number(argv[i+1])) {
                    game_data->attempts = my_atoi(argv[i+1]);
                }
            }
            else {
                printf("Unknown option!");
            }
        }
        i += 1;
    }
    return game_data;
}