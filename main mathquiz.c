#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// to define a structure to hold the player's data
struct Player {
	char name[50];
	int score;
};

void saveScore(char name[], int score);
void displayLeaderboard();
void searchPlayer(char searchName[]);


int main() {
    int mainMenu, mode, answer, correctResult;
	int num1, num2, min, max, currentScore = 0;
	char playerName[50], yesNo;
    int keepPlaying = 1;

	srand(time(NULL)); // Seed randomizer once at the start

    printf("Enter your name to start: ");
    scanf("%s", playerName);

	//Main Menu
 while (keepPlaying) {
        printf("\n=== Welcome to the Math Quiz ===\n");
        printf("1. Start the quiz\n");
        printf("2. View the Leaderboard\n");
        printf("3. Search for a Player\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &mainMenu);
       
    // Mode selection menu
	if (mainMenu == 1) {
        printf("\nSelect Mode: \n");
        printf("1. Easy (10 Points)\n");
        printf("2. Medium (20 Points)\n");
        printf("3. Hard (30 Points)\n");
        printf("Choice:\n");
            scanf("%d", &mode);


		//Ranges setting based on difficulty
                   // Set ranges based on mode
            if (mode == 1) {min = 1; max = 20; } 
            else if (mode == 2) {min = 21; max = 50; } 
            else if (mode == 3) {min = 51; max = 100; }
            else {printf("Invalid mode!\n"); continue; }

            // Generate Numbers
            num1 = (rand() % (max - min + 1)) + min;
            num2 = (rand() % (max - min + 1)) + min;
            correctResult = (mode == 1) ? (num1 + num2) : (num1 * num2);

            // Quiz Loop (stays on this question until correct)
            while (1) {
                printf("What is %d %s %d? ", num1, (mode == 1 ? "+" : "x"), num2);
                scanf("%d", &answer);
                if (answer == correctResult) {
                    int points = (mode == 1) ? 10 : (mode == 2 ? 20: 30);
                    currentScore += points;
                    printf("Correct! +%d points. Current Total: %d\n", points, currentScore);
                    break; // Exit the question loop
                } else {
                    printf("Incorrect. Try Again!\n");
                }
            }
        }
