#include "floor.cpp"
#include<vector>
#pragma once
using namespace std;

class building{
    private:
        vector<floors*>floorList;
        ElevatorScheduler* es;
    public:
        building(int noOfFloors, ElevatorScheduler* es){
            cout<<"Creating a building ......"<<endl;
            floorList.resize(noOfFloors);

            for(int i=0;i<noOfFloors;i++){
                floorList[i]=new floors(i,es);
            }

        }

        floors* getfloor(int id){
            if(id>floorList.size()){
                cout<<"no such floor exist"<<endl;
                return NULL;
            }
            return floorList[id];
        }


};