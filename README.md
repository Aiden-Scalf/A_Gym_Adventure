# A Gym Adventure

A command-line board game written in C++ where every space on the board is a workout. Roll the dice, move forward, and do the exercise you land on. Reach space 30 to win.

## How It Works

1. Enter your name when the game starts.
2. Press **Enter** to roll a six-sided die.
3. Your roll is added to your position on the board.
4. If you land on a workout space, the game tells you which exercise to do.
5. The first time your position reaches **30 or more**, you win.

The workouts repeat in a cycle of 10 spaces, so spaces 1, 11, and 21 all give the same exercise, and so on.

## Workout Spaces

| Space (+10 each lap) | Workout |
|---|---|
| 1, 11, 21 | 10 push-ups |
| 2, 12, 22 | 10 squats |
| 3, 13, 23 | 10 dips |
| 4, 14, 24 | 10 burpees |
| 5, 15, 25 | 10 sit-ups |
| 6, 16, 26 | 60-second plank |
| 7, 17, 27 | 60 seconds of mountain climbers |
| 8, 18, 28 | 60 seconds of scissor kicks |
| 9, 19, 29 | 60 seconds of Supermans |
| 10, 20, 30 | 10 pistol squats |

## Getting Started

### Requirements

- A C++ compiler with C++11 support or newer (GCC, Clang, or MSVC)
- CMake

### Build and Run

```bash
git clone https://github.com/Aiden-Scalf/A_Gym_Adventure.git
cd A_Gym_Adventure
mkdir build && cd build
cmake ..
cmake --build .
./A_Gym_Adventure
```

You can also compile it directly without CMake:

```bash
g++ main.cpp -o gym_adventure
./gym_adventure
```

## Code Overview

- **`Player`** stores the player's name and score (their position on the board).
- **`Game`** runs the turns, tracks the current turn number, checks for workout spaces, and decides when the player has won.
- **`dice_roll()`** returns a random number from 1 to 6, seeding the random generator on the first call.

## Possible Future Improvements

- Support multiple players
- Let players enter names with spaces
- Add a difficulty setting with different rep counts
- Replace the long `if/else` chain in `check_workout()` with a lookup table
- Add a replay option

## Author

Aiden Scalf
