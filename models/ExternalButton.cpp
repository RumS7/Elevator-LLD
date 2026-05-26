#include "ElevatorScheduler.cpp"
#include "ElevatorController.cpp"
#pragma once

class ExternalButton{
        private:
            ElevatorScheduler* es;

        public:
            ExternalButton(ElevatorScheduler* es):es(es){}

            void press(int floor,directions dir){
                ElevatorController* ec=es->assignElevator(floor,dir);
                ec->AddFloor(floor);
            }
};