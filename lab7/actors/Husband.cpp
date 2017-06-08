#include <vector>
#include <cstring>
#include "../shops/Shop.cpp"
#include "../shops/EquipmentShop.cpp"
#include "../shops/ProductsShop.cpp"
#include "../data/OrderResult.h"


class Husband {

    /*singleton code start*/
private:
    Husband(){
        shops[0] = new EquipmentShop;
        shops[1] = new ProductsShop;
    }
public:
    static Husband* getInstance()
    {
        static Husband* instance;
        if(!instance)
            instance = new Husband;
        return instance;
    }
    Husband(Husband const&) = delete;
    Husband& operator= (Husband const&) = delete;
    /*singleton code end*/

public:
    OrderResult acceptOrder(std::vector<string> itemsToBuy){
        std::vector<Product> totalItems = getAllItems();
        return executeOrder(itemsToBuy, totalItems);
    }

private:
    static const int NUMBER_OF_SHOPS = 2;
    Shop* shops[NUMBER_OF_SHOPS];
    std::vector<Product> getAllItems() {
        std::vector<Product> totalItems;
        for (int i = 0; i < NUMBER_OF_SHOPS; i++)
            for (int j = 0; j < shops[i]->getListSize(); j++)
                totalItems.push_back(shops[i]->getListOfItems()[j]);
        return totalItems;
    }
    OrderResult executeOrder(std::vector<string> itemsToBuy, std::vector<Product> totalItems) {
        std::vector<Product> bought;
        for (int i = 0; i < itemsToBuy.size(); i++)
            for (int j = 0; j < totalItems.size(); j++)
                if (itemsToBuy[i].compare(totalItems[j].name) == 0) //if names are equal
                    bought.push_back(totalItems[j]);
        int sum = calcSum(bought);
        return OrderResult{bought, totalItems, sum};
    }
    int calcSum(std::vector<Product> bought) {
        int sum = 0;
        for (int i = 0; i < bought.size(); i++)
            sum += bought[i].price;
        return sum;
    }
};