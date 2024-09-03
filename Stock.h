#ifndef STOCK_H
#define STOCK_H

#include "Inventory.h"

class Stock {
public:
    Stock(Inventory &inventory);
    void checkStockLevels() const;

private:
    Inventory &inventory;
};

#endif // STOCK_H
