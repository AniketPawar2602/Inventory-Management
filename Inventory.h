#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Inventory {
public:
    void addItem(int itemNumber, const string &name, int quantity, double price);
    void deleteItem(int itemNumber);
    void updateItem(int itemNumber, int quantity, double price);
    void viewItems() const;
    bool buyItem(int itemNumber, int quantity);
    bool viewItemsEmpty() const;
    void saveToFile(const string &filename) const;
    void loadFromFile(const string &filename);

private:
    vector<Item> items;
    Item* findItemByNumber(int itemNumber);
};

#endif // INVENTORY_H
