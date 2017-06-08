#include <iostream>
#include "Shop.cpp"

using namespace std;

class ProductsShop : public Shop {
public:
    ProductsShop() {
        listOfItems.push_back(Product{"Sausage", 80});
        listOfItems.push_back(Product{"Butter", 70});
        listOfItems.push_back(Product{"Milk", 300});
        listOfItems.push_back(Product{"Potato", 40});
    }
};
