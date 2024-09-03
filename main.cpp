#include <iostream>
#include "Authentication.h"
#include "Inventory.h"
#include "Item.h"
#include "Stock.h"

const std::string FILENAME = "inventory.dat";

void ownerMenu(Inventory &inventory) {
    int choice;
    int itemNumber;
    std::string name;
    int quantity;
    double price;

    do {
        std::cout << "\nOwner Menu:\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Delete Item\n";
        std::cout << "3. Update Item\n";
        std::cout << "4. View Items\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter item number: ";
            std::cin >> itemNumber;
            std::cout << "Enter item name: ";
            std::cin >> name;
            std::cout << "Enter item quantity: ";
            std::cin >> quantity;
            std::cout << "Enter price per item: ";
            std::cin >> price;
            inventory.addItem(itemNumber, name, quantity, price);
            break;
        case 2:
            std::cout << "Enter item number to delete: ";
            std::cin >> itemNumber;
            inventory.deleteItem(itemNumber);
            break;
        case 3:
            std::cout << "Enter item number to update: ";
            std::cin >> itemNumber;
            std::cout << "Enter new quantity: ";
            std::cin >> quantity;
            std::cout << "Enter new price per item: ";
            std::cin >> price;
            inventory.updateItem(itemNumber, quantity, price);
            break;
        case 4:
            inventory.viewItems();
            break;
        case 5:
            std::cout << "Logging out...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

void customerMenu(Inventory &inventory) {
    int choice;
    int itemNumber;
    int quantity;

    do {
        std::cout << "\nCustomer Menu:\n";
        std::cout << "1. Buy Item\n";
        std::cout << "2. View Items\n";
        std::cout << "3. Leave Shop\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (inventory.viewItemsEmpty()) {
                std::cout << "No items available for purchase.\n";
            } else {
                std::cout << "Enter item number: ";
                std::cin >> itemNumber;
                std::cout << "Enter item quantity: ";
                std::cin >> quantity;
                if (inventory.buyItem(itemNumber, quantity)) {
                    std::cout << "Purchase successful.\n";
                } else {
                    std::cout << "Item not available or insufficient quantity.\n";
                }
            }
            break;
        case 2:
            inventory.viewItems();
            break;
        case 3:
            std::cout << "Leaving the shop...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    Authentication auth;
    Inventory inventory;
    int role;
    std::string username, password;

    // Load inventory from file
    inventory.loadFromFile(FILENAME);

    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Login as Owner\n";
        std::cout << "2. Enter as Customer\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> role;

        switch (role) {
        case 1:
            std::cout << "Login as Owner\n";
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (auth.login(username, password)) {
                ownerMenu(inventory);
            } else {
                std::cout << "Invalid credentials.\n";
            }
            break;
        case 2:
            std::cout << "Enter as Customer\n";
            customerMenu(inventory);
            break;
        case 3:
            // Save inventory to file before exiting
            inventory.saveToFile(FILENAME);
            std::cout << "Exiting program...\n";
            return 0; // Exit the program
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
