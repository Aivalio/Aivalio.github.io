#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 10
#define DELAY 100000

// Ορισμός των κινήσεων για τη "κούραση"
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Δομή για το σώμα της "οχιές"
typedef struct {
    int x;
    int y;
} SnakeSegment;

SnakeSegment snake[100]; // Μέγιστο μέγεθος σώματος
int snakeLength = 3;     // Αρχικό μήκος
int direction = RIGHT;   // Αρχική κατεύθυνση
int foodX, foodY;        // Θέση τροφής

// Δημιουργία τυχαίας θέσης για την τροφή
void generateFood() {
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

// Εκτύπωση του παιχνιδιού (πίνακας)
void draw() {
    clear();
    for (int i = 0; i < WIDTH+2; i++)
        mvprintw(0, i, "#");
    for (int i = 1; i < HEIGHT+1; i++) {
        mvprintw(i, 0, "#");
        for (int j = 1; j < WIDTH+1; j++) {
            if (i == snake[0].y && j == snake[0].x)
                mvprintw(i, j, "O");  // Κεφάλι της οχιές
            else {
                int bodyPart = 0;
                for (int k = 1; k < snakeLength; k++) {
                    if (snake[k].x == j && snake[k].y == i) {
                        mvprintw(i, j, "o"); // Σώμα της οχιές
                        bodyPart = 1;
                    }
                }
                if (!bodyPart) mvprintw(i, j, " ");
            }
        }
        mvprintw(i, WIDTH+1, "#");
    }
    for (int i = 0; i < WIDTH+2; i++)
        mvprintw(HEIGHT+1, i, "#");

    mvprintw(foodY, foodX, "*"); // Εκτύπωση τροφής
    refresh();
}

// Ελέγχει αν ο χρήστης έκανε κίνηση
void input() {
    int ch = getch();
    switch (ch) {
        case 'w': if (direction != DOWN) direction = UP; break;
        case 's': if (direction != UP) direction = DOWN; break;
        case 'a': if (direction != RIGHT) direction = LEFT; break;
        case 'd': if (direction != LEFT) direction = RIGHT; break;
        case 'q': exit(0); // Εξοδος από το παιχνίδι
    }
}

// Κίνηση της "οχιές"
void moveSnake() {
    int prevX = snake[0].x;
    int prevY = snake[0].y;
    int prev2X, prev2Y;
    snake[0].x = (direction == RIGHT) ? snake[0].x + 1 : (direction == LEFT) ? snake[0].x - 1 : snake[0].x;
    snake[0].y = (direction == DOWN) ? snake[0].y + 1 : (direction == UP) ? snake[0].y - 1 : snake[0].y;

    for (int i = 1; i < snakeLength; i++) {
        prev2X = snake[i].x;
        prev2Y = snake[i].y;
        snake[i].x = prevX;
        snake[i].y = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

// Έλεγχος αν η "οχιές" έφαγε την τροφή
void checkFood() {
    if (snake[0].x == foodX && snake[0].y == foodY) {
        snakeLength++;
        generateFood();
    }
}

// Έλεγχος για συντριβή ή αν η "οχιές" έφαγε τον εαυτό της
int checkCollision() {
    if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
        return 1; // Κοπή στον τοίχο
    }
    for (int i = 1; i < snakeLength; i++) {
        if (snake[i].x == snake[0].x && snake[i].y == snake[0].y) {
            return 1; // Κοπή στο σώμα της οχιές
        }
    }
    return 0;
}

int main() {
    srand(time(0)); // Αρχικοποίηση του τυχαίου αριθμού

    initscr(); // Ενεργοποίηση ncurses
    timeout(0); // Δεν υπάρχει καθυστέρηση μεταξύ των εκδόσεων
    cbreak();
    noecho();
    curs_set(0); // Απόκρυψη του δείκτη του ποντικιού
    keypad(stdscr, TRUE);

    generateFood(); // Δημιουργία τροφής

    while (1) {
        draw();      // Εκτύπωση του πίνακα
        input();     // Λήψη εισόδου από το χρήστη
        moveSnake(); // Κίνηση της "οχιές"
        checkFood(); // Έλεγχος αν φάγαμε τροφή

        if (checkCollision()) { // Έλεγχος αν έχουμε συντριβή
            mvprintw(HEIGHT / 2, WIDTH / 2 - 7, "GAME OVER!");
            refresh();
            usleep(2000000); // Δώσε χρόνο να το δει ο χρήστης
            break;
        }

        usleep(DELAY); // Καθυστέρηση για να μην είναι το παιχνίδι πολύ γρήγορο
    }

    endwin(); // Τερματισμός ncurses
    return 0;
}
