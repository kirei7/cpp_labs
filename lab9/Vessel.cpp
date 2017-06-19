#include <string>
#include <stdio.h>

using namespace std;

class Vessel {
public:
    Vessel(int capacity) {
        cap = capacity;
        honeyQuantity = 0;
    }
    bool isFull() {
        return cap == honeyQuantity;
    }
    bool putHoney(string beeName) {
        if (honeyQuantity < cap)
        {
            honeyQuantity++;
            printf("%s-%d ", beeName.c_str(), honeyQuantity);
            return false;
        }
        else
            return true;

    }
    void empty() {
        honeyQuantity = 0;
    }
    int cap;
    volatile int honeyQuantity;
};

