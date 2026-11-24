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

// Count total gems on the map
int countGems(char map[ROWS][COLS]) {
    int count = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (map[r][c] == '*') {
                count++;
            }
        }
    }
    return count;
}

void drawMap(char map[ROWS][COLS], int px, int py, int score, int gemsLeft) {
    // Clear terminal screen cross-platform
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("=== ASCII QUEST (STAGE 2) ===\n");
    printf("Move: W/A/S/D + Enter | Quit: Q + Enter\n");
    printf("Score: %d | Gems Left: %d\n\n", score, gemsLeft);

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            // Render player dynamically without altering floor tile
            if (r == py && c == px) {
                printf("@");
            } else {
                printf("%c", map[r][c]);
            }
        }
        printf("\n");
    }

    printf("\nLegend: @=Player  *=Gem (+10)  E=Exit (all gems)  #=Wall\n");
}

Direction parseInput(char ch, int *shouldQuit) {
    // Normalize uppercase letters to lowercase
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

void tryMove(char map[ROWS][COLS], int *px, int *py, Direction dir,
             int *score, int *gemsLeft, int *hasWon, int *exitLockedMsg) {
    int nx = *px;
    int ny = *py;

    // Compute candidate target coordinates
    switch (dir) {
        case DIR_UP:    ny--; break;
        case DIR_DOWN:  ny++; break;
        case DIR_LEFT:  nx--; break;
        case DIR_RIGHT: nx++; break;
        case DIR_NONE:  return;
    }

    // Check bounds and solid wall collision
    if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && map[ny][nx] != '#') {
        char targetTile = map[ny][nx];

        // Collect gem and clear tile
        if (targetTile == '*') {
            *score += 10;
            (*gemsLeft)--;
            map[ny][nx] = '.';
        }
        // Unlock exit only after collecting all gems
        else if (targetTile == 'E') {
            if (*gemsLeft == 0) {
                *hasWon = 1;
            } else {
                *exitLockedMsg = 1;
                return;
            }
        }

        // Commit player movement
        *px = nx;
        *py = ny;
    }
}

int main(void) {
    char map[ROWS][COLS] = {
        "####################",
        "#...*....#......*..#",
        "#..###...#...###...#",
        "#........#.........#",
        "#..*...#####...*...#",
        "#..................#",
        "#...###.....###....#",
        "#..*..#.......#..E.#",
        "#.....#.......#....#",
        "####################"
    };

    int px = 1;
    int py = 1;
    int score = 0;
    int gemsLeft = countGems(map);
    int shouldQuit = 0;
    int hasWon = 0;
    int exitLockedMsg = 0;

    // Main game loop stops on quit or win
    while (!shouldQuit && !hasWon) {
        drawMap(map, px, py, score, gemsLeft);

        if (exitLockedMsg) {
            printf("\nExit is locked! Collect all gems first (%d left).\n", gemsLeft);
            exitLockedMsg = 0;
        }

        printf("Enter move: ");
        char input;
        if (scanf(" %c", &input) != 1) {
            break;
        }

        Direction dir = parseInput(input, &shouldQuit);
        tryMove(map, &px, &py, dir, &score, &gemsLeft, &hasWon, &exitLockedMsg);
    }

    // Render final state and summary
    drawMap(map, px, py, score, gemsLeft);

    if (hasWon) {
        printf("\nStage cleared! Final Score: %d\n", score);
    } else {
        printf("\nGame exited. Final Score: %d\n", score);
    }

    return 0;
}
