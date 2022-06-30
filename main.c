#include "source.h"

void intro() {
    printf("Will you find the secret code?\n");
}
void play(t_game_data* game_data) {
    int current_attempts = 0;
    while (current_attempts < game_data->attempts) {
        // process_round;
    }
}

int main(int argc, char** argv) {
    intro();
    t_game_data* game_data = init_struct();
    parse_params(game_data, argc, argv);
    printf("secret code: %s\n",game_data->secret_code);
    printf("attempts: %d\n", game_data->attempts);
    play(game_data);
    return 0;
}
