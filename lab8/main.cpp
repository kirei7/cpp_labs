#include <iostream>
#include <time.h>
#include "Sorter.cpp"

using namespace std;

float* createRandomArray(int size);
void displayArray(float* array, int size);
void displayResult(SortResult result);


int main() {

    static const int ARRAY_SIZE = 5000;

    srand (time(NULL));

    float* array1 = createRandomArray(ARRAY_SIZE);
    float* array2 = createRandomArray(ARRAY_SIZE);

    Sorter sorter;
    SortResult result = sorter.sort(array1, array2, ARRAY_SIZE);

    displayResult(result);

    return 0;
}

float* createRandomArray(int size) {
    float* array = new float[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = ((float)(rand() % 1000))/10;
    }
    return array;
}
void displayArray(float* array, int size) {
    cout<<endl<<"[";
    for (int i = 0; i < size; i++) {
        printf("%2.1f", array[i]);
        if(i != (size - 1)) cout<<", ";
    }
    cout<<"]"<<endl;
}
void displayResult(SortResult result) {
    cout<<"The winner is: '"<<result.threadName<<"' with time "<<result.timeWinner<<endl;
    cout<<"Looser time "<<result.timeLoser<<endl;
}