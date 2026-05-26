#include "SelectionStrategy.cpp"
#include "../enums/directions.cpp"
#include "../models/ElevatorController.cpp"
#pragma once

class NearestElevator:public SelectionStrategy{
    private:
        
    public:
        ElevatorController* selectElevator(int floor, directions dir,vector<ElevatorController*>ec){
            int minDist=INT_MAX;
            ElevatorController* ans=NULL;
            for(auto x:ec){
                int ecDir=x->getcar()->getDirection();
                int ecFloor=x->getcar()->getCurrentFloor();

                if(dir==ecDir){
                    if(dir==directions::UP && floor>=ecFloor){
                        if(abs(floor-ecFloor)<minDist){
                            minDist=min(minDist,abs(floor-ecFloor));
                            ans=x;
                        }
                        
                    }
                    else if(dir==directions::DOWN && floor<=ecFloor){
                        if(abs(floor-ecFloor)<minDist){
                            minDist=min(minDist,abs(floor-ecFloor));
                            ans=x;
                        }
                    }
                }
                
            }
            if(ans==NULL){
                for(auto x:ec){
                    int ecDir=x->getcar()->getDirection();
                    if(ecDir==directions::IDLE){
                        ans=x;
                        break;
                    }
                }
            }

            if(ans==NULL){
                ans=ec[0];
            }

            return ans;
        }
};