#include "Vessel.cpp"
using namespace std;

class Bear {
public:
    Bear(Vessel* vessel) {
        this->vessel = vessel;
    }
    void wakeUp(string beeName) {
        vessel->empty();
    }

private:
    Vessel* vessel;
};
