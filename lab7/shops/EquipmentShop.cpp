#include <iostream>
#include "Shop.cpp"

using namespace std;

class EquipmentShop : public Shop {
public:
    EquipmentShop() {
        listOfItems.push_back(Product{"Sony", 100});
        listOfItems.push_back(Product{"Samsung", 80});
        listOfItems.push_back(Product{"Sharp", 70});
        listOfItems.push_back(Product{"Apple", 300});
        listOfItems.push_back(Product{"Aser", 40});
        listOfItems.push_back(Product{"Bread", 110});
    }
};

