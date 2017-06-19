#include <windows.h>
#include <time.h>
#include "Bear.cpp"
#include <iostream>

using namespace std;

const DWORD mutexFree = 4294967295;

class Bee {
public:
    Bee(HANDLE* mutex, Bear* bear, Vessel* vessel, string name) {
        cout<<"creating bee"<<endl;
        this->bear = bear;
        this->vessel = vessel;
        this->name = name;
        this->mutex = mutex;

        /*pbeeparam pbeeparameter;
        pbeeparameter->bee = this;

        HANDLE thread;
        DWORD ThreadID;
        thread = CreateThread(
                NULL,       // default security attributes
                0,          // default stack size
                Bee::makeBeeWork,
                pbeeparameter,       // no thread function arguments
                0,          // default creation flags
                &ThreadID); // receive thread identifier*/
    }
/*
    static void makeBeeWork(LPVOID lpParam) {
        pbeeparam params;
        params = (pbeeparam) lpParam;
        params->bee->bringHoney();
    }*/

    void bringHoney() {
        /*int delay = rand() % 3 + 1;

        Sleep(delay * 500);*/
        DWORD dwWaitResult;
        dwWaitResult = WaitForSingleObject(
                mutex,    // handle to mutex
                INFINITE);  // no time-out interval

        switch (dwWaitResult)
        {
            // The thread got ownership of the mutex
            case mutexFree:
                try {
                    bool isFull = vessel->putHoney(name);
                    if (isFull)
                    {
                        bear->wakeUp(name);
                        printf("\n%s awakened a bear! Vessel is empty now\n", name.c_str());
                    }
                } catch(...){}
                        // Release ownership of the mutex object
                        /*if (! ReleaseMutex(mutex))
                        {
                            cout<<"mutex error";
                        }*/
                ReleaseMutex(mutex);
                break;
        }


    }

    void sayHello() {
        cout<<"hello"<<endl;
    }

private:
    Bear* bear;
    Vessel* vessel;
    string name;

    HANDLE* mutex;

};