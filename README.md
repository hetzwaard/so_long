# so_long

## Overview
The **so_long** project is a simple 2D game built using the MLX42 library. The goal of the game is to collect all collectibles on the map and reach the exit while avoiding obstacles. This project allowed me to explore graphical programming concepts, including rendering, animations, and event handling.

---

## Features
- **Graphical Rendering:** Utilizes the MLX42 library for rendering images and handling window events.
- **Custom Game Logic:**
  - Player movement with keyboard input.
  - Collectibles that must be gathered to unlock the exit.
  - Obstacles and walls to navigate around.
- **Map Parsing:**
  - Reads a `.ber` file to generate the game map.
  - Validates the map for proper structure and gameplay requirements.
- **Animations:** Smooth animations for player movement and collectibles.
- **Event Handling:**
  - Keyboard input for movement.
  - Window close event handling.
- **Error Handling:** Ensures proper error messages for invalid maps or missing assets.

---

## Game Mechanics
1. **Objective:** Collect all items on the map and reach the exit.
2. **Player Movement:** Move the player using the arrow keys or `WASD`.
3. **Map Requirements:**
   - Must have one player, one exit, and at least one collectible.
   - Surrounded by walls to prevent the player from leaving the map.
4. **Win Condition:** Collect all items and reach the exit.

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