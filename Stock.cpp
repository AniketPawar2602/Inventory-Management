#include "Stock.h"
#include <iostream>

Stock::Stock(Inventory &inventory) : inventory(inventory) {}

void Stock::checkStockLevels() const {
    std::cout << "Checking stock levels...\n";
    inventory.viewItems();
}
