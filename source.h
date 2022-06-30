#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game_data {
    char* secret_code;
    int attempts;
} t_game_data;

char* my_strcpy(char* param_1, char* param_2);
int my_strlen(char* param_1);
int my_atoi(char* param_1);
int is_valid_code(char* code);
int is_number(char* str);
t_game_data* init_struct();
t_game_data* parse_params(t_game_data* game_data, int argc, char** argv);
