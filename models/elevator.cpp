#include<iostream>
#include "../enums/GateState.cpp"
#include "../enums/directions.cpp"
#pragma once
using namespace std;


class elevator{
    private:
        int id;
        int currFloor;
        directions dir;
        GateState door;
    
    public:
        elevator(int id){
            this->id=id;
            this->currFloor=0;
            dir=directions::IDLE;
            door=GateState::CLOSE;
        }

        directions getDirection() {return dir;}
        int getCurrentFloor(){ return currFloor;}
        GateState getGateState(){ return door;}
        int getid() {return id;}

        void moveToFloor(int floor){
            this->closeDoor();
            if(floor==currFloor){
                this->openDoor();
                return;
            }
            else if(floor>currFloor){
                dir=directions::UP;
                for(int i=currFloor+1;i<=floor;i++){
                    cout<<"Moving Up the elevator:"<<id<<" & currFloor is "<<i<<endl;
                }
                cout<<"Stopping the elevator:"<<id<<" at "<<floor<<endl;
                openDoor();
            }
            else{
                dir=directions::DOWN;
                for(int i=currFloor-1;i>=floor;i--){
                    cout<<"Moving Down the elevator:"<<id<<" & currFloor is "<<i<<endl;
                }
                cout<<"Stopping the elevator:"<<id<<" at "<<floor<<endl;
                openDoor();
            }

            this->currFloor=floor;
        }

        void closeDoor(){
            cout<<"Closing the door of elevator"<<id<<" stand back"<<endl;
            door=GateState::CLOSE;
        }

        void openDoor(){
            cout<<"Opening the door of elevator"<<id<<" stand back"<<endl;
            door=GateState::OPEN;
        }

        void setDirection(directions d){
            dir=d;
            return;
        }

        
        
};