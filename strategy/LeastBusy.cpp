#include "SelectionStrategy.cpp"
#include "../enums/directions.cpp"
#include "../models/ElevatorController.cpp"
#pragma once

class LeastBusy:public SelectionStrategy{
    
    public:
        ElevatorController* selectElevator(int floor, directions dir,vector<ElevatorController*>ec){
            ElevatorController* ans=NULL;
            int minLoad=INT_MAX;

            for(auto x:ec){
                int load=x->getload();
                if(load<minLoad){
                    ans=x;
                    minLoad=load;
                }
            }

            return ans;
        }          
};