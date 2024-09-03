#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

void Inventory::addItem(int itemNumber, const std::string &name, int quantity, double price) {
    items.emplace_back(itemNumber, name, quantity, price);
}

void Inventory::deleteItem(int itemNumber) {
    auto it = std::remove_if(items.begin(), items.end(), [itemNumber](const Item &item) {
        return item.getItemNumber() == itemNumber;
    });
    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "Item deleted successfully.\n";
    } else {
        std::cout << "Item not found.\n";
    }
}

void Inventory::updateItem(int itemNumber, int quantity, double price) {
    Item* item = findItemByNumber(itemNumber);
    if (item) {
        item->setQuantity(quantity);
        item->setPrice(price);
        std::cout << "Item updated successfully.\n";
    } else {
        std::cout << "Item not found.\n";
    }
}

Item* Inventory::findItemByNumber(int itemNumber) {
    for (auto &item : items) {
        if (item.getItemNumber() == itemNumber) {
            return &item;
        }
    }
    return nullptr;
}

void Inventory::viewItems() const {
    std::cout << "\nInventory Items:\n";
    std::cout << std::left << std::setw(10) << "Item No." 
              << std::setw(20) << "Name" 
              << std::setw(10) << "Quantity" 
              << std::setw(15) << "Price per item" 
              << std::setw(15) << "Total Price" << "\n";
    std::cout << "--------------------------------------------------------------------------------\n";
    for (const auto &item : items) {
        std::cout << std::left << std::setw(10) << item.getItemNumber()
                  << std::setw(20) << item.getName()
                  << std::setw(10) << item.getQuantity()
                  << std::setw(15) << std::fixed << std::setprecision(2) << item.getPrice()
                  << std::setw(15) << std::fixed << std::setprecision(2) << (item.getPrice() * item.getQuantity()) << "\n";
    }
}

bool Inventory::viewItemsEmpty() const {
    return items.empty();
}

bool Inventory::buyItem(int itemNumber, int quantity) {
    Item* item = findItemByNumber(itemNumber);
    if (item) {
        if (item->getQuantity() >= quantity) {
            item->setQuantity(item->getQuantity() - quantity);
            std::cout << "Purchase successful.\n";
            return true;
        } else {
            std::cout << "Insufficient quantity available.\n";
        }
    } else {
        std::cout << "Item not found.\n";
    }
    return false;
}

void Inventory::saveToFile(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        size_t size = items.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (const auto &item : items) {
            int itemNumber = item.getItemNumber();
            std::string name = item.getName();
            int quantity = item.getQuantity();
            double price = item.getPrice();

            file.write(reinterpret_cast<const char*>(&itemNumber), sizeof(itemNumber));
            size_t nameSize = name.size();
            file.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
            file.write(name.c_str(), nameSize);
            file.write(reinterpret_cast<const char*>(&quantity), sizeof(quantity));
            file.write(reinterpret_cast<const char*>(&price), sizeof(price));
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Inventory::loadFromFile(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        items.clear(); // Clear existing items
        size_t size;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        for (size_t i = 0; i < size; ++i) {
            int itemNumber;
            size_t nameSize;
            std::string name;
            int quantity;
            double price;

            file.read(reinterpret_cast<char*>(&itemNumber), sizeof(itemNumber));
            file.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
            name.resize(nameSize);
            file.read(&name[0], nameSize);
            file.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
            file.read(reinterpret_cast<char*>(&price), sizeof(price));

            addItem(itemNumber, name, quantity, price);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
}
