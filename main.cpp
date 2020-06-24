#include <chrono>
#include <ostream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>

#define SLEEP_TIME 500

enum StateMachine {
    State_1,
    State_2,
    State_3,
    State_4,
    State_5
};

int main(){
    std::cout << "Application started..." << std::endl;
    std::cout << "Process Id: " << ::getpid() << std::endl;
    StateMachine n_state = State_1;

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
            break;
        case State_5:
            std::cout << "State_5 reached" << std::flush;
            n_state = State_1;
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
