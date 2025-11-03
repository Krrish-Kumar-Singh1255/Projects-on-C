# 🧮 Simple Calculator (C Program)

## 📘 Overview
This is a **Simple Calculator** written in **C**, capable of performing basic arithmetic operations such as:
- Addition ➕  
- Subtraction ➖  
- Multiplication ✖️  
- Division ➗  
- Modulus (%)  
- Power (xʸ)

It takes two floating-point inputs from the user and performs the selected operation, displaying the result up to two decimal places.

---

## ⚙️ Features
✅ User-friendly text-based interface  
✅ Uses functions for modular structure  
✅ Supports float inputs  
✅ Handles invalid operations like division or modulus by zero  
✅ Uses `math.h` for power and modulus functions  
✅ Loops until the user chooses to exit  

---

## 🧩 Menu Options
| Option | Operation     | Description |
|:------:|:--------------|:-------------|
| 1 | Add | Adds two numbers |
| 2 | Subtract | Subtracts the second number from the first |
| 3 | Multiply | Multiplies two numbers |
| 4 | Divide | Divides the first number by the second |
| 5 | Modulus | Returns remainder using `fmod()` |
| 6 | Power | Calculates base raised to exponent |
| 7 | Exit | Ends the program |

---

## 🚀 How to Compile & Run
```bash
# Compile
gcc calculator.c -o calculator -lm

# Run
./calculator
