#include "source.h"

void intro() {
    printf("Will you find the secret code?\n");
}
int process_round(char* orig_code, int round) {
    //output current round
    //wait for input
    //check code
    //output results
    printf("\n---\nRound: %d\n", round);
    //printf("%s\n", orig_code);
    printf(">");
    fflush(stdout);
    char* input_code = input();
    char* user_code = cut(input_code);
    free(input_code);
    int res_code = 1;
    if (is_valid_code(user_code)==0) {
        res_code = check_code(orig_code, user_code);
    }
    free(user_code);
    return res_code;
}

void play(t_game_data* game_data) {
    int current_attempts = 0;
    while (current_attempts < game_data->attempts) {
        // process_round;
        int res_code = process_round(game_data->secret_code, current_attempts);
        current_attempts += 1;
        if (res_code == 0) {
            printf("Congratz! You did it!\n");
        }
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
