#include <chrono>
#include <ostream>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>

#define SLEEP_TIME 700

enum StateMachine {
    State_1,
    State_2,
    State_3,
    State_4,
    State_5
};

void freeSomething(void *ptr){
    free(ptr);
}

int zeroDivide(){
    int nDivider = 5;
    int nRes = 0;
    while(nDivider > 0){
        nDivider--;
        nRes = 5 / nDivider;
    }
    return nRes;
}

int main(int argc, char* argv[]){
    bool b_enable_crash_1 = false;
    bool b_enable_crash_2 = false;

    std::cout << "Application started..." << std::endl;
    std::cout << "Process Id: " << ::getpid() << std::endl;
    StateMachine n_state = State_1;

    /* Throw SIGABRT */
    if(argc > 1 && strcmp(argv[1], "-c1") == 0){
        std::cout << "crash mode" << std::endl;
        b_enable_crash_1 = true;
    }
    /* Zero Divide */
    if(argc > 1 && strcmp(argv[1], "-c2") == 0){
        std::cout << "crash mode" << std::endl;
        b_enable_crash_2 = true;
    }

    while(true){
        switch(n_state){

        case State_1:
            std::cout << "State_1 reached" << std::flush;
            n_state = State_2;
            break;
        case State_2:
            std::cout << "State_2 reached" << std::flush;
            n_state = State_3;
            break;
        case State_3:
            std::cout << "State_3 reached" << std::flush;
            n_state = State_4;
            break;
        case State_4:
            std::cout << "State_4 reached" << std::flush;
            n_state = State_5;
            if(b_enable_crash_1){
                /* not covered by -Wall flag */
                int nTmp = 5;
                int *ptrNull = &nTmp;
                freeSomething(ptrNull);
            }
            break;
        case State_5:
            std::cout << "State_5 reached" << std::flush;
            n_state = State_1;
            if(b_enable_crash_2){
                zeroDivide();
            }
            break;
        default:
            std::cout << "Default state reached" << std::flush;
            break;
        }
        /* Move cursor back to beginning */
        std::cout << '\r' << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
   }    


    do{
       std::cout << "hey" << std::endl; 
    } while (getchar() == '\n');
   
    return 0;
}
