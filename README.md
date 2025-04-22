# 🛒 Inventory Management System - C++

## 📌 Project Overview

This is a simple **Inventory Management System** built using **C++** with file handling. The system supports two types of users: **Owner** and **Customer**. Owners can manage the inventory by adding or deleting items, while customers can view and buy products.

All data is stored in a `.dat` file to ensure persistence between sessions.

## 🧠 Features

**Authentication**
- Login system for **Owner** and **Customer**
- User-role-based access control

**Owner Functionalities**
- Add new items to inventory  
- Delete existing items  
- View current stock details  

**Customer Functionalities**
- View available items  
- Buy products  
- Exit the system  

**File Handling**
- Uses `.dat` file for storing item data  
- Ensures data persistence between sessions  

## 📂 Project Structure

```
InventoryManagementSystem/
│
├── Authentication.cpp  
├── Inventory.cpp  
├── Item.cpp  
├── Stock.cpp  
├── User.cpp  
├── Main.cpp  
├── items.dat            (Data file storing all item records)  
└── README.md  
```

## ⚙️ Technologies Used

- Language: C++
- Concepts:
  - Object-Oriented Programming (OOP)
  - File Handling (`fstream`)
  - Exception Handling (`try-catch`)
  - Role-based system design

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (e.g., g++)

### Steps to Run

Clone the repository:
```bash
git clone https://github.com/your-username/inventory-management-cpp.git
cd inventory-management-cpp
```

Compile the code:
```bash
g++ Main.cpp Authentication.cpp Inventory.cpp Stock.cpp User.cpp Item.cpp -o output
```

Run the executable:
```bash
./output
```

## 💡 Future Enhancements

- Add search functionality  
- Implement item quantity update instead of deletion  
- GUI version using Qt or C++/CLI  
- Password encryption for better security  

## 🙌 Author

**Aniket Satish Pawar**  
🔗 [LinkedIn](https://www.linkedin.com/in/aniket-pawar-2b8587271/)
