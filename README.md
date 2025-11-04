# 🎮 Tic-Tac-Toe Game in C

A terminal-based **Tic-Tac-Toe** game written in C with both **Single Player (vs Computer)** and **Multiplayer (vs Player)** modes.  
It features two difficulty levels, smart computer moves, score tracking, and a clean command-line interface.

---

## 🧠 Overview

This project demonstrates:
- Use of **2D arrays** for the game board  
- **Structures** for score management  
- **Game logic implementation** with AI opponent  
- **Randomized turn selection**  
- Cross-platform **clear screen** feature  
- Option for **Human vs Human** gameplay  

---

## ⚙️ Features

✅ **Two Game Modes**  
- 🎮 Player vs Computer  
- 👥 Player vs Player  

✅ **Two Difficulty Levels** (for Computer)  
- 🧍‍♂️ *HUMAN (Standard)* — Basic random and defensive AI  
- 🧠 *GOD Mode* — Unbeatable computer logic  

✅ **Additional Features**
- Randomized first turn  
- Automatic score tracking (Wins, Losses, Draws)  
- Clean game board display  
- Replay option after each round  
- Works on Windows, Linux, and macOS  

---

## 🧩 Data Structures

### Structure used:
```c
typedef struct {
    int player;
    int computer;
    int draw;
} Score;
