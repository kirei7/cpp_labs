#include "Bee.cpp"

HANDLE ghMutex;
const int THREADS_NUM = 4;

typedef struct beeparam {
    Bee bee;
} beeparam, *pbeeparam;

static DWORD WINAPI makeBeeWork(LPVOID lpParam) {
    pbeeparam params;
    params = (pbeeparam) lpParam;
    for (int i = 0; i < 20; i++)
        params->bee.bringHoney();
}

class Forest {
public:
    void live() {
        Vessel vessel(5);
        Bear pooh(&vessel);
        ghMutex = CreateMutex(
                NULL,              // default security attributes
                FALSE,             // initially not owned
                NULL);             // unnamed mutex
        if (ghMutex == NULL) {
            printf("CreateMutex error: %d\n", GetLastError());
            return;
        }

        Bee bee1(&ghMutex, &pooh, &vessel, "bee1");
        Bee bee2(&ghMutex, &pooh, &vessel, "bee2");
        Bee bee3(&ghMutex, &pooh, &vessel, "bee3");
        Bee bee4(&ghMutex, &pooh, &vessel, "bee4");


        HANDLE hThreadArray[THREADS_NUM];
        DWORD dwThreadIdArray[THREADS_NUM];
        pbeeparam pbeeparams[THREADS_NUM];

        pbeeparams[0] = (pbeeparam) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(beeparam));
        pbeeparams[1] = (pbeeparam) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(beeparam));
        pbeeparams[2] = (pbeeparam) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(beeparam));
        pbeeparams[3] = (pbeeparam) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(beeparam));


        pbeeparams[0]->bee = bee1;
        pbeeparams[1]->bee = bee2;
        pbeeparams[2]->bee = bee3;
        pbeeparams[3]->bee = bee4;

        hThreadArray[0] = CreateThread(
                NULL,                   // default security attributes
                0,                      // use default stack size
                makeBeeWork,       // thread function name
                pbeeparams[0],          // argument to thread function
                CREATE_SUSPENDED,                      // use default creation flags
                &dwThreadIdArray[0]);
        hThreadArray[1] = CreateThread(
                NULL,                   // default security attributes
                0,                      // use default stack size
                makeBeeWork,       // thread function name
                pbeeparams[1],          // argument to thread function
                CREATE_SUSPENDED,                      // use default creation flags
                &dwThreadIdArray[1]);
        hThreadArray[2] = CreateThread(
                NULL,                   // default security attributes
                0,                      // use default stack size
                makeBeeWork,       // thread function name
                pbeeparams[2],          // argument to thread function
                CREATE_SUSPENDED,                      // use default creation flags
                &dwThreadIdArray[2]);
        hThreadArray[3] = CreateThread(
                NULL,                   // default security attributes
                0,                      // use default stack size
                makeBeeWork,       // thread function name
                pbeeparams[3],          // argument to thread function
                CREATE_SUSPENDED,                      // use default creation flags
                &dwThreadIdArray[3]);

        ResumeThread(hThreadArray[0]);
        ResumeThread(hThreadArray[1]);
        ResumeThread(hThreadArray[2]);
        ResumeThread(hThreadArray[3]);

        WaitForMultipleObjects(THREADS_NUM, hThreadArray, TRUE, INFINITE);
        for (int i = 0; i < THREADS_NUM; i++) {
            CloseHandle(hThreadArray[i]);
        }
    }


};
