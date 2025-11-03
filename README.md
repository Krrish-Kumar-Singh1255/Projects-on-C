# Number Guessing Game (C Project)

## Overview
This is a simple **Number Guessing Game** written in **C language**.  
The computer randomly generates a number between **1 and 20**, and the player has to guess it.  
After each guess, hints are provided — whether to go higher or lower — until the player guesses correctly.

---

## How to Play
1. Run the program.
2. The system will choose a random number between **1 and 20**.
3. Enter your guess when prompted.
4. You’ll get hints after each guess:
   - **Enter Lower number** → if your guess is too high.
   - **Enter Higher number** → if your guess is too low.
5. Keep guessing until you find the correct number.
6. The program will display how many attempts you made.

---

## How to Run

### Using GCC (Windows / Linux / macOS)
```bash
gcc number_guessing_game.c -o game
./game
