#include "source.h"

t_game_data* init_struct() {
    t_game_data* d = (t_game_data*)malloc(sizeof(t_game_data));
    d->secret_code = (char*) malloc(5);
    d->secret_code[4] = '\0';
    my_strcpy(d->secret_code, rand_code());
    d->attempts = 10;
    fflush(stdout);
    return d;
}