# so_long

## Overview
The **so_long** project is a simple 2D game built using the MLX42 library. The objective of the game is to collect all collectibles on the map and reach the exit while avoiding obstacles. This project explores graphical programming concepts such as rendering, animations, event handling, and map validation.

---

## Features
- **Graphical Rendering:** Utilizes the MLX42 library for rendering images and managing window events.
- **Custom Game Logic:**
  - Player movement using keyboard input (`WASD` or arrow keys).
  - Collectibles that must be gathered to unlock the exit.
  - Obstacles and walls to navigate around.
- **Map Parsing and Validation:**
  - Reads a `.ber` file to generate the game map.
  - Validates the map for proper structure, ensuring it meets gameplay requirements.
- **Animations:** Smooth animations for player movement and collectible interactions.
- **Event Handling:**
  - Keyboard input for movement.
  - Window close event handling.
- **Error Handling:** Provides detailed error messages for invalid maps, missing assets, or runtime issues.

---

## Functions
### **Core Functions**
- **`so_long(char *map_ber)`**  
  Initializes the game by loading the map, validating it, and setting up the MLX42 environment. It also starts the game loop.
  
- **`map_read(int fd, int size)`**  
  Reads the map file and stores it in a 2D array.

- **`map_init(t_map *map)`**  
  Initializes the map structure, including player position, collectible count, and other game elements.

- **`map_build(t_map *map)`**  
  Builds the game map by rendering the appropriate textures for walls, spaces, collectibles, and the exit.

- **`flood_fill(t_map *map)`**  
  Validates the map to ensure all collectibles and the exit are reachable from the player's starting position.

- **`move(mlx_key_data_t key, void *param)`**  
  Handles player movement based on keyboard input and updates the game state accordingly.

- **`error_exit(int i, t_map *map)`**  
  Handles errors by freeing allocated resources and exiting the program with an appropriate error message.

### **Utility Functions**
- **`map_name(char *str)`**  
  Validates the map file name to ensure it ends with `.ber`.

- **`map_line(int fd)`**  
  Counts the number of lines in the map file.

- **`map_dup(t_map *map)`**  
  Creates a duplicate of the map for validation purposes.

- **`ft_free_arr(char **res)`**  
  Frees a dynamically allocated 2D array.

---

## Game Mechanics
1. **Objective:** Collect all items on the map and reach the exit.
2. **Player Movement:** Move the player using the arrow keys or `WASD`.
3. **Map Requirements:**
   - Must have one player, one exit, and at least one collectible.
   - Surrounded by walls to prevent the player from leaving the map.
4. **Win Condition:** Collect all items and reach the exit.

---

## General Process
1. **Map Loading and Validation:**
   - The game starts by reading the `.ber` map file.
   - The map is validated for structure, ensuring it contains one player, one exit, and at least one collectible.
   - A flood-fill algorithm checks if all collectibles and the exit are reachable.

2. **Game Initialization:**
   - The MLX42 library initializes the game window and loads textures for the player, walls, collectibles, and the exit.
   - The map is rendered based on the parsed `.ber` file.

3. **Game Loop:**
   - The game enters a loop where it listens for keyboard input to move the player.
   - The player's position is updated, and the game state is checked after each move (e.g., collectible count, win condition).

4. **Win or Error Handling:**
   - If the player collects all items and reaches the exit, the game ends successfully.
   - If an error occurs (e.g., invalid map, missing assets), the program exits with an error message.

---

## How to Use
### Prerequisites
- A C compiler (e.g., `gcc`).
- MLX42 library installed on your system.
- GNU Make.

### Compilation
To compile the project, run the following command:
```bash
make