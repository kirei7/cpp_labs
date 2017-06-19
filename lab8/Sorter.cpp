#include <ctime>
#include <windows.h>

#include "data/SortResult.h"
#include "BubbleSort.cpp"

typedef struct SortData {
    float* array;
    int size;
    double timeDuration;
}SortData, *PSortData;

class Sorter {
public:
    SortResult sort(float* array1, float* array2, int arrSize) {
        HANDLE  hThreadArray[2];
        DWORD   dwThreadIdArray[2];

        PSortData sortData[2];
        sortData[0] = (PSortData) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(SortData));
        sortData[1] = (PSortData) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(SortData));
        sortData[0]->array = array1;
        sortData[1]->array = array2;
        sortData[0]->size = arrSize;
        sortData[1]->size = arrSize;

        hThreadArray[0] = CreateThread(
                NULL,                   // default security attributes
                0,                      // use default stack size
                sortWithTimer,       // thread function name
                sortData[0],          // argument to thread function
                CREATE_SUSPENDED,                      // use default creation flags
                &dwThreadIdArray[0]);
        hThreadArray[1] = CreateThread(
                NULL,                   // default security attributes
                1,                      // use default stack size
                sortWithTimer,       // thread function name
                sortData[1],          // argument to thread function
                CREATE_SUSPENDED,                      // use default creation flags
                &dwThreadIdArray[1]);

        ResumeThread(hThreadArray[1]);
        ResumeThread(hThreadArray[0]);

        WaitForMultipleObjects(2, hThreadArray, TRUE, INFINITE);

        double first = sortData[0]->timeDuration;
        double second = sortData[1]->timeDuration;

        for(int i=0; i<2; i++)
        {
            CloseHandle(hThreadArray[i]);
            if(sortData[i] != NULL)
            {
                HeapFree(GetProcessHeap(), 0, sortData[i]);
                sortData[i] = NULL;    // Ensure address is not reused.
            }
        }


        double timeWin;
        double timeLose;
        std::string name;
        if(first < second) {
            timeWin = first;
            timeLose = second;
            name = "first thread";
        } else if(first > second){
            timeWin = second;
            timeLose = first;
            name = "second thread";
        } else {
            timeWin = first;
            name = "threads even";
        }

        SortResult result{timeWin, timeLose, name};

        return result;
    }

private:
    static BubbleSort algorithm;
    double durations[2];
    static DWORD WINAPI sortWithTimer(LPVOID lpParam) {
        PSortData sortData;
        sortData = (PSortData)lpParam;
        float* array = sortData->array;
        int size = sortData->size;

        std::clock_t start;
        double duration;
        start = std::clock();

        BubbleSort::sort(array, size);

        duration = ( std::clock() - start );

        sortData->timeDuration = duration;
        return 0;
    }
};
