# 🏦 Bank Management System in C

A simple yet powerful **Bank Management System** written in C that allows users to **create accounts**, **deposit and withdraw money**, **check balances**, and **view all customer details (admin access)**.  
This project uses **file handling** to store and retrieve user data persistently.

---

## 🧠 Overview

This system demonstrates:
- Use of **structures (`struct`)** for storing account data  
- **File handling (`.dat` binary file)** for data persistence  
- **Account creation, deposit, withdrawal, and balance check**  
- **Admin-protected access** to view all accounts  
- Random account number generation and duplicate prevention  

---

## ⚙️ Features

✅ Create new bank accounts  
✅ Deposit and withdraw money securely  
✅ Check account balance anytime  
✅ Persistent data storage using `account.dat`  
✅ Password-protected admin access to view all accounts  
✅ Cross-platform compatible  

---

## 🧩 Data Structure

Each account is stored as a structure:
```c
typedef struct {
    int acc_no;
    char account_holder_name[30];
    float money;
} Account;
