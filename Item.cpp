#include "Item.h"

Item::Item(int itemNumber, const std::string &name, int quantity, double price)
    : itemNumber(itemNumber), name(name), quantity(quantity), price(price) {}

int Item::getItemNumber() const {
    return itemNumber;
}

std::string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

double Item::getPrice() const {
    return price;
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Item::setPrice(double price) {
    this->price = price;
}
