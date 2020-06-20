#include <ostream>
#include <stdio.h>
#include <iostream>
#include <vector>

enum StateMachine {
    State_1,
    State_2,
    State_3,
    State_4,
    State_5
};

int main(){
    printf("Application started\n\n");
    
    StateMachine n_state = State_1;

    switch(n_state){

    case State_1:
        std::cout << "State_1 reached" << std::endl;
        break;
    case State_2:
        std::cout << "State_2 reached" << std::endl;
        break;
    case State_3:
        std::cout << "State_3 reached" << std::endl;
        break;
    case State_4:
        std::cout << "State_4 reached" << std::endl;
        break;
    case State_5:
        std::cout << "State_5 reached" << std::endl;
        break;
    default:
        std::cout << "Default state reached" << std::endl;
        break;
    }


    std::cout << "Application started..." << std::endl;
    do{
       std::cout << "hey" << std::endl; 
    } while (getchar() == '\n');
   
    return 0;
}
