#include <vector>
#include <string>

#include "Husband.cpp"

class Wife {
public:
    Wife() {
        husband = Husband::getInstance();

        productsToBuy.push_back("Sony");
        productsToBuy.push_back("Bread");
        productsToBuy.push_back("Lenovo");
        productsToBuy.push_back("Onion");

    }
    void orderProducts() {
        OrderResult result = husband->acceptOrder(productsToBuy);
        display(result);
    }

private:
    std::vector<string> productsToBuy;
    Husband* husband;

    void display(OrderResult result) {
        std::cout<<"Total list:"<<endl;
        displayListOfItems(result.total);
        std::cout<<endl<<"Bought:"<<endl;
        displayListOfItems(result.bought);
        std::cout<<"Total price = "<<result.boughtPrice<<endl;
    }
    void displayListOfItems(std::vector<Product> products) {
        for (int i = 0; i < products.size(); i++) {
            std::cout<<products[i].name<<" - "<<products[i].price<<endl;
        }
    }
};