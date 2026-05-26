#include "ElevatorController.cpp"
#pragma once

class InternalButton{
    private:
        ElevatorController* ec;

    public:
        InternalButton(ElevatorController* ec){
            this->ec=ec;
        }

        void press(int floor){
            ec->AddFloor(floor);
        }

};