#include <iostream>

// Function to check if the game has been won
bool hasGameBeenWon(int tower[3][3]) {
    if (tower[2][0] == 3 && tower[2][1] == 2 && tower[2][2] == 1)
        return true;
    return false;
}

// Function to display the towers
void displayTowers(int towers[3][3]) {
    printf("\n");
    for (int j = 2; j >= 0; j--) {
        for (int i = 0; i < 3; i++) {
            if (towers[i][j] == 0)
                printf("  |  ");
            else if (towers[i][j] == 1)
                printf("   *  ");
            else if (towers[i][j] == 2)
                printf("  **  ");
            else if (towers[i][j] == 3)
                printf(" ***  ");
        }
        printf("\n");
    }
    printf("  1     2     3\n");
}

// Function to check if a move is valid
bool isSmaller(int from, int to, int tower[3][3]) {
    int firstdisc = 0;
    int seconddisc = 0;
    while (from <= 3 && to <= 3 && from >= 1 && to >= 1) {
        // Find the top disc on the 'from' tower
        for (int i = 2; i >= 0; i--) {
            if (tower[from - 1][i] > 0) {
                firstdisc = tower[from - 1][i];
                break;
            }
        }

        // Find the top disc on the 'to' tower
        for (int i = 2; i >= 0; i--) {
            if (tower[to - 1][i] > 0) {
                seconddisc = tower[to - 1][i];
                break;
            }
        }

        return firstdisc == 0 || (seconddisc == 0 || firstdisc < seconddisc);
    }
}

int main() {
    bool gameover = false;
    int from, to;
    int tower[3][3] = {
        {3, 2, 1},
        {0, 0, 0},
        {0, 0, 0}
    };

    printf("Welcome to the Tower of Hanoi game\n");
    displayTowers(tower);

    while (!gameover) {
        // Get user input for move
        printf("Enter the tower you want to move from: ");
        scanf("%d", &from);
        printf("\nEnter the tower you want to move to: ");
        scanf("%d", &to);

        // Check if the move is valid
        if (isSmaller(from, to, tower)) {
            int disk = 0;
            for (int i = 2; i >= 0; i--) {
                if (tower[from - 1][i] > 0) {
                    disk = tower[from - 1][i];
                    tower[from - 1][i] = 0;
                    break;
                }
            }

            // Place the disk on the 'to' tower
            for (int i = 0; i < 3; i++) {
                if (tower[to - 1][i] == 0) {
                    tower[to - 1][i] = disk;
                    break;
                }
            }

            displayTowers(tower);

            // Check if the game has been won
            if (hasGameBeenWon(tower)) {
                printf("Congratulations! You've won the game!\n");
                gameover = true;

                // Ask the user if they want to play again
                int playagain = 0;
                printf("Press 0 to play again or any other number to quit: ");
                scanf("%d", &playagain);
                if (playagain == 0)
                    main(); // Restart the game if the user wants to play again
            }
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}
