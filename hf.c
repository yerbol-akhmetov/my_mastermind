#include "source.h"

char* my_strcpy(char* param_1, char* param_2) {
    int i = 0;
    while (param_2[i]!='\0') {
        param_1[i] = param_2[i];
        i++;
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

char* input() {
    char* buffer = (char*) malloc(101);
    buffer[100] = '\0';
    read(0, buffer, 100);
    fflush(stdout);
    return buffer;
}

char* cut(char* str) {
    char* new_str = (char*)malloc(5);
    new_str[4]='\0';
    for (int i=0; i<4; i++) {
        new_str[i] = str[i];
    }
    return new_str;
}

int check_code(char* orig_code, char* user_code) {
    int wellplaced = count_wellplaced(orig_code, user_code);
    int missplaced = count_missplaced(orig_code, user_code);
    printf("Wellplaced: %d\n", wellplaced);
    printf("Missplaced: %d\n", missplaced);

    if (wellplaced==4) {
        return 0;
    }
    else {
        return 1;
    }
}
int count_wellplaced(char* orig_code, char* user_code) {
    int count = 0;
    for (int i=0; i < 4; i++) {
        if (orig_code[i]==user_code[i]) {
            count += 1;
        }
    }
    return count;
}
int count_missplaced(char* orig_code, char* user_code) {
    int count = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (i!=j && orig_code[i]==user_code[j]) {
                count += 1;
            }
        }
    }
    return count;
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
                if (is_number(argv[i+1])==0) {
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