#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void toss(char *choice) {
    srand(time(0));
    int toss_result = rand() % 2;
    if (toss_result == 0) {
        printf("Machine won the toss and chose to bat first.\n");
        *choice = 'b';
    } else {
        printf("Player won the toss. Choose (b) for batting or (f) for fielding: ");
        scanf(" %c", choice);
    }
}

int machine_batting() {
    int machine_score = 0, ball, machine_run;

    printf("\nMachine is batting.\n");

    for (ball = 1; ball <= 6; ball++) {
        printf("Ball %d: Guess the machine's run (0-6): ", ball);
        int player_guess;
        scanf("%d", &player_guess);

        machine_run = rand() % 7; // Machine randomly selects its run (0-6)

        if (player_guess == machine_run) {
            printf("Out! Player guessed correctly.\n");
            break;
        } else {
            machine_score += machine_run;
            printf("Machine scored %d runs.\n", machine_run);
        }
    }

    printf("Machine's final score: %d\n", machine_score);
    return machine_score;
}

void player_batting(int target) {
    int player_score = 0, ball, player_run;

    printf("\nPlayer is batting to chase a target of %d runs.\n", target);

    for (ball = 1; ball <= 6; ball++) {
        printf("Ball %d: Enter your run (0-6): ", ball);
        scanf("%d", &player_run);

        int machine_guess = rand() % 7; // Machine guesses player's run

        if (player_run == machine_guess) {
            printf("Out! Machine guessed correctly.\n");
            break;
        } else {
            player_score += player_run;
            printf("Player scored %d runs.\n", player_run);
        }

        if (player_score > target) {
            printf("Player wins! Score: %d\n", player_score);
            return;
        }
    }

    if (player_score <= target) {
        printf("Player loses! Final score: %d\n", player_score);
    }
}

int main() {
    char choice;
    toss(&choice);

    if (choice == 'b') {
        // Machine bats first
        int target = machine_batting() + 1;
        player_batting(target);
    } else {
        // Player bats first
        printf("\nPlayer is batting first.\n");
        int player_score = 0, ball, player_run;

        for (ball = 1; ball <= 6; ball++) {
            printf("Ball %d: Enter your run (0-6): ", ball);
            scanf("%d", &player_run);

            int machine_guess = rand() % 7; // Machine guesses player's run

            if (player_run == machine_guess) {
                printf("Out! Machine guessed correctly.\n");
                break;
            } else {
                player_score += player_run;
                printf("Player scored %d runs.\n", player_run);
            }
        }

        printf("Player's final score: %d\n", player_score);

        printf("\nMachine is batting to chase a target of %d runs.\n", player_score + 1);
        int machine_score = machine_batting();

        if (machine_score >= player_score + 1) {
            printf("Machine wins!\n");
        } else {
            printf("Player wins!\n");
        }
    }

    return 0;
}
