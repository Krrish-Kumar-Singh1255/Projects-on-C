# ⏳ Multi-Task Progress Bar Simulation in C

A simple **C program** that visually simulates multiple tasks running in parallel using dynamic progress bars.  
Each task updates independently with random speeds until all reach 100%.

---

## 🧠 Overview

This project demonstrates:
- **Structs** and **arrays** in C  
- Use of **loops** and **random values** for simulation  
- **Cross-platform screen clearing** (Windows/Linux)  
- **Dynamic progress visualization** using ASCII bars  

---

## ⚙️ Features

✅ Multiple progress bars updating simultaneously  
✅ Randomized progress speeds per task  
✅ Real-time animation using `sleep()`  
✅ Clean and platform-independent output  
✅ Customizable bar length and task count  

---

## 🧩 Code Explanation

### 🧱 Task Structure
Each task tracks its ID, progress, and step speed.
```c
typedef struct {
  int id;
  int progress;
  int step;
} Task;
