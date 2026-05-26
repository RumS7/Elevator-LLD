#include "ElevatorController.cpp"
#include "../strategy/SelectionStrategy.cpp"
#include "../strategy/LeastBusy.cpp"
#include "../strategy/NearestElevator.cpp"
#pragma once

class ElevatorScheduler{
    private:
        vector<ElevatorController*>ControllerList;
        SelectionStrategy* ss;

    public:
        ElevatorScheduler(vector<ElevatorController*>ControllerList){
            this->ControllerList=ControllerList;
        }

        void addStrategy(SelectionStrategy* ss){
            this->ss=ss;
        }

        ElevatorController* assignElevator(int floor,directions dir){
            return ss->selectElevator(floor,dir,ControllerList);
        }


};