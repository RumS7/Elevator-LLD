#include "ExternalButton.cpp"
#include "InternalButton.cpp"
#include "ElevatorController.cpp"
#pragma once

class floors{
    private:
        int id;
        ExternalButton* up;
        ExternalButton* down;
       
    
    public:
        floors(int id,ElevatorScheduler* es){
            this->id=id;
            up=new ExternalButton(es);
            down=new ExternalButton(es);
        }

        void pressUP(int floor){
            up->press(floor,directions::UP);
        }

        void pressDOWN(int floor){
            down->press(floor,directions::DOWN);
        }

};