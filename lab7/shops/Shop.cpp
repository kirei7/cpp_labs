#ifndef UNTITLED_SHOP_H
#define UNTITLED_SHOP_H

#include <vector>
#include "../data/Product.h"

class Shop {
public:
    virtual unsigned long getListSize() {
        return listOfItems.size();
    }
    virtual std::vector<Product> getListOfItems() {
        return listOfItems;
    }

protected:
    std::vector<Product> listOfItems;
};


#endif //UNTITLED_SHOP_H
