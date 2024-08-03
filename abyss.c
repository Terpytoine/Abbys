#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int has_sword;   // items in game
    int health;
    int has_key;
    int potions;
    int puzzle_solved;
} Player;

typedef struct
{
    int health;    //health and damage for enemy
    int damage;
} Enemy;

void print_status(Player *player)  // status update
{
    printf("Status: Health = %d, Sword = %s, Key = %s, Potions = %d, Puzzle Solved = %s\n", player->health,
           player->has_sword ? "Yes" : "No", player->has_key ? "Yes" : "No", player->potions, player->puzzle_solved ? "Yes" : "No");
}

void save_game(Player *player)  // save game if you wish
{
    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL)
    {
        printf("Error saving game.\n");
        return;
    }
    fprintf(file, "%d %d %d %d %d\n", player->has_sword, player->health, player->has_key, player->potions, player->puzzle_solved);
    fclose(file);
    printf("Game saved successfully.\n");
}

void load_game(Player *player) //loading into new charecter
{
    FILE *file = fopen("savegame.txt", "r");
    if (file == NULL)
    {
        printf("No saved game found.\n");
        return;
    }
    fscanf(file, "%d %d %d %d %d", &player->has_sword, &player->health, &player->has_key, &player->potions, &player->puzzle_solved);
    fclose(file);
    printf("Game loaded successfully.\n");
}

void combat(Player *player, Enemy *enemy)  //combat with enemys
{
    printf("You encounter an enemy with %d health and %d damage.\n", enemy->health, enemy->damage);

    while (player->health > 0 && enemy->health > 0)
    {
        printf("You attack the enemy!\n");
        enemy->health -= 10;
        if (enemy->health <= 0)
        {
            printf("You defeated the enemy!\n");
            return;
        }

        printf("The enemy attacks you!\n");
        player->health -= enemy->damage;
        if (player->health <= 0)
        {
            printf("You have died in combat. Game over.\n");
            exit(0);
        }
    }
}

void puzzle(Player *player) //puzzle for in game 
{
    char answer[20];
    printf("Puzzle: What is 3 + 4?\n");
    printf("Enter your answer: ");
    scanf("%s", answer);

    if (strcmp(answer, "7") == 0)
    {
        printf("Correct! The puzzle is solved.\n");
        player->puzzle_solved = 1;
    }
    else
    {
        printf("Incorrect. The puzzle remains unsolved.\n");
    }
}

void room1(Player *player);
void room2(Player *player);
void room3(Player *player);
void room4(Player *player);
void room5(Player *player);

void room1(Player *player)
{
    int choice;
    printf("Room 1: You are in a dark forest. There is a path to the left and right.\n");
    printf("1. Go left\n2. Go right\n3. Save Game\n4. Load Game\n");
    printf("Enter your choice (1, 2, 3 or 4): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You encounter a friendly wizard who gives you a magical sword.\n");
        player->has_sword = 1;
        room2(player);
    }
    else if (choice == 2)
    {
        printf("You fall into a pit and lose some health.\n");
        player->health -= 20;
        if (player->health <= 0)
        {
            printf("You have died. Game over.\n");
            exit(0);
        }
        room3(player);
    }
    else if (choice == 3)
    {
        save_game(player);
        room1(player);
    }
    else if (choice == 4)
    {
        load_game(player);
        room1(player);
    }
    else
    {
        printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        room1(player);
    }
}

void room2(Player *player)
{
    int choice;
    printf("Room 2: You enter a clearing with a beautiful fountain. There are paths ahead.\n");
    printf("1. Drink from the fountain\n2. Go to the forest path\n3. Check the fountain\n4. Solve a puzzle\n");
    printf("Enter your choice (1, 2, 3 or 4): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        if (player->has_sword)
        {
            printf("The fountain heals you! You gain some health.\n");
            player->health += 20;
        }
        else
        {
            printf("The fountain does nothing for you.\n");
        }
        room3(player);
    }
    else if (choice == 2)
    {
        printf("You head back to the forest path.\n");
        room1(player);
    }
    else if (choice == 3)
    {
        printf("You find a hidden key at the bottom of the fountain!\n");
        player->has_key = 1;
        room3(player);
    }
    else if (choice == 4)
    {
        if (player->puzzle_solved)
        {
            printf("You have already solved the puzzle in this game.\n");
        }
        else
        {
            puzzle(player);
        }
        room3(player);
    }
    else
    {
        printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        room2(player);
    }
}

void room3(Player *player)
{
    int choice;
    Enemy enemy = {30, 15}; // Example enemy with 30 health and 15 damage
    printf("Room 3: You find yourself at a crossroad. There are two ways to go.\n");
    printf("1. Take the left path\n2. Take the right path\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You encounter a wild beast! ");
        combat(player, &enemy);
        if (player->health > 0)
        {
            printf("With your sword, you defeat the beast and find a treasure chest.\n");
            room4(player);
        }
    }
    else if (choice == 2)
    {
        printf("You wander into a serene meadow and find a peaceful village. You have escaped the dangers of the forest.\n");
        printf("You win! Congratulations!\n");
        exit(0);
    }
    else
    {
        printf("Invalid choice. Please enter 1 or 2.\n");
        room3(player);
    }
}

void room4(Player *player)
{
    int choice;
    printf("Room 4: You enter a dungeon. There are two doors: one locked and one open.\n");
    printf("1. Try to open the locked door\n2. Enter the open door\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        if (player->has_key)
        {
            printf("You use the key to open the locked door and find a treasure!\n");
            printf("You win! Congratulations!\n");
            exit(0);
        }
        else
        {
            printf("The door is locked. You need a key to open it.\n");
            room3(player);
        }
    }
    else if (choice == 2)
    {
        printf("You find a hidden passage leading to freedom. You win!\n");
        exit(0);
    }
    else
    {
        printf("Invalid choice. Please enter 1 or 2.\n");
        room4(player);
    }
}

int main()
{
    char play_again;
    Player player;

    srand(time(NULL)); // Seed the random number generator

    do
    {
        player.has_sword = 0;
        player.health = 100;
        player.has_key = 0;
        player.potions = 1; // Starting with one potion
        player.puzzle_solved = 0;

        printf("Welcome to the ABYSS an Adventure Game!\n");
        print_status(&player);

        room1(&player);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    }
    while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}
