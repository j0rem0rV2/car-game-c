#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 20
#define HEIGHT 10

int car_position = WIDTH / 2;
int obstacle_position = 0;
int obstacle_row = 0;
int score = 0;

// Função para verificar se uma tecla foi pressionada (Linux)
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Limpa a tela usando códigos ANSI
void clear_screen() {
    printf("\033[H\033[J");
}

void draw_game() {
    clear_screen();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1 && j == car_position) {
                printf("^");  // Carro
            } else if (i == obstacle_row && j == obstacle_position) {
                printf("#");  // Obstáculo
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
}

void update_game() {
    obstacle_row++;

    if (obstacle_row == HEIGHT) {
        obstacle_row = 0;
        obstacle_position = rand() % WIDTH;
        score++;
    }

    if (obstacle_row == HEIGHT - 1 && obstacle_position == car_position) {
        printf("Game Over! Final Score: %d\n", score);
        exit(0);
    }
}

void handle_input() {
    if (kbhit()) {
        char key = getchar();
        if (key == 'a' && car_position > 0) {
            car_position--;
        } else if (key == 'd' && car_position < WIDTH - 1) {
            car_position++;
        }
    }
}

int main() {
    srand(time(NULL));

    // Configura o terminal para não exibir entrada do teclado
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (1) {
        draw_game();
        update_game();
        handle_input();
        usleep(200000);  // 200ms
    }

    // Restaura as configurações originais do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}