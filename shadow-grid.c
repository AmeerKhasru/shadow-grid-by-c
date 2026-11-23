#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

typedef enum {
    DIR_NONE = 0,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

void drawMap(char map[ROWS][COLS], int px, int py) {
    // Clear screen (works on Windows and Unix-like terminals)
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("=== STAGE 1: DUNGEON MOVEMENT ===\n");
    printf("Move: W/A/S/D + Enter | Quit: Q + Enter\n\n");

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == py && c == px) {
                printf("@");
            } else {
                printf("%c", map[r][c]);
            }
        }
        printf("\n");
    }

    printf("\nPosition: (%d, %d)\n", px, py);
}

Direction parseInput(char ch, int *shouldQuit) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A');
    }

    switch (ch) {
        case 'w': return DIR_UP;
        case 's': return DIR_DOWN;
        case 'a': return DIR_LEFT;
        case 'd': return DIR_RIGHT;
        case 'q': *shouldQuit = 1; return DIR_NONE;
        default:  return DIR_NONE;
    }
}

void tryMove(char map[ROWS][COLS], int *px, int *py, Direction dir) {
    int nx = *px;
    int ny = *py;

    switch (dir) {
        case DIR_UP:    ny--; break;
        case DIR_DOWN:  ny++; break;
        case DIR_LEFT:  nx--; break;
        case DIR_RIGHT: nx++; break;
        case DIR_NONE:  return;
    }

    // Boundary and wall check
    if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && map[ny][nx] != '#') {
        *px = nx;
        *py = ny;
    }
}

int main(void) {
    char map[ROWS][COLS] = {
        "####################",
        "#........#.........#",
        "#..###...#...###...#",
        "#........#.........#",
        "#......#####.......#",
        "#..................#",
        "#...###.....###....#",
        "#.....#.......#....#",
        "#.....#.......#....#",
        "####################"
    };

    int px = 1;
    int py = 1;
    int shouldQuit = 0;

    while (!shouldQuit) {
        drawMap(map, px, py);

        printf("Enter move: ");
        char input;
        if (scanf(" %c", &input) != 1) {
            break;
        }

        Direction dir = parseInput(input, &shouldQuit);
        tryMove(map, &px, &py, dir);
    }

    printf("Exited game.\n");
    return 0;
}