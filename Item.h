#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(int itemNumber, const std::string &name, int quantity, double price);
    
    int getItemNumber() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    void setQuantity(int quantity);
    void setPrice(double price);

private:
    int itemNumber;
    std::string name;
    int quantity;
    double price;
};

#endif // ITEM_H
