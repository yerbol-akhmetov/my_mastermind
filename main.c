#include "source.h"

void intro() {
    printf("Will you find the secret code?\n");
}

int main(int argc, char** argv) {
    intro();
    t_game_data* game_data = init_struct();
    printf("%s\n",game_data->secret_code);
    return 0;
}