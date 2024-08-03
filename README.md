## Abyss: A Simple CLI Adventure Game

### Overview
Abyss is a simple command-line interface (CLI) adventure game written in C. In this game, players navigate through different rooms, solve puzzles, combat enemies, and make choices that impact their progress. The game includes features like saving and loading progress and simple combat mechanics.

### Code Explanation

1. **Structures:**
   - `Player`: Holds information about the player, such as health, possession of items (sword, key), number of potions, and whether a puzzle has been solved.
   - `Enemy`: Contains information about the enemy's health and damage.

2. **Functions:**
   - `print_status(Player *player)`: Displays the player's current status, including health, items, and puzzle progress.
   - `save_game(Player *player)`: Saves the player's current game state to a file named `savegame.txt`.
   - `load_game(Player *player)`: Loads the player's game state from `savegame.txt`.
   - `combat(Player *player, Enemy *enemy)`: Handles the combat between the player and an enemy.
   - `puzzle(Player *player)`: Presents a simple math puzzle to the player.
   - `room1(Player *player)`, `room2(Player *player)`, `room3(Player *player)`, `room4(Player *player)`: Define different rooms and scenarios the player can encounter.

3. **Gameplay:**
   - The game begins in `room1`, where players can choose different paths, save or load the game, and interact with in-game elements.
   - In `room2`, players can drink from a fountain, find a key, or solve a puzzle.
   - In `room3`, players can encounter enemies and either defeat them or take another path.
   - In `room4`, players must use a key to unlock a door or find another way to win.
   - The `main` function initializes the player’s stats, starts the game loop, and asks if the player wants to play again.

### How to Compile

To compile the Abyss program, follow these steps:

1. **Save the Code:**
   Save the provided C code to a file named `abyss.c`.

2. **Open Terminal:**
   Open a terminal or command prompt on your computer.

3. **Compile the Code:**
   Use the `gcc` compiler to compile the code. Run the following command:
   ```bash
   gcc abyss.c -o abyss
   ```

4. **Run the Game:**
   Execute the compiled program with:
   ```bash
   ./abyss
   ```

### Additional Notes

- The game saves progress in a file named `savegame.txt`. Make sure the program has permission to read and write files in the directory.
- This game is designed to be simple and may serve as a foundation for more complex text-based adventures.

Feel free to contribute by improving the code or adding new features!
