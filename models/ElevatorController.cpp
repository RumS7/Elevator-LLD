#include "elevator.cpp"
#include <iostream>
#include <thread>
#include<set>
#include "../enums/GateState.cpp"
#include "../enums/directions.cpp"
#pragma once
using namespace std;


class ElevatorController{
    private:
        elevator* ec;
        set<int,greater<int>>downMax;
        set<int>upMin;
        thread worker;
        mutex mx;
        condition_variable cv;
        bool stop;

        void enqueue(int floor){
            unique_lock<mutex>lock(mx);
            directions dir=ec->getDirection();
            int curr= ec->getCurrentFloor();
            if(curr==floor){
                lock.unlock();
                ec->openDoor();
                
                
            }
            else if((floor<curr)){
                downMax.insert(floor);
                lock.unlock();
                
            }
            else{
                upMin.insert(floor);
                lock.unlock();
                
            }
            
            cv.notify_one(); 
        }
    
    public:
        ElevatorController(elevator* ec): ec(ec),stop(false){}

        void AddFloor(int floor){
            enqueue(floor);
        }

        

        void start(){
            worker=thread(&ElevatorController::run,this);
        }

        void run(){

            while(1){
                unique_lock<mutex>lock(mx);
                cv.wait(lock,[&]{
                    return stop || !upMin.empty() || !downMax.empty();
                });

                if(stop){
                    cout<<"Stopping the elevator with id: "<<ec->getid()<<endl;
                    break;
                }
                int floor;
                directions dir=ec->getDirection();
                if(dir==directions::UP){
                    if(!upMin.empty()){
                        floor=*upMin.begin();
                        upMin.erase(upMin.begin());
                    }
                    else{
                        ec->setDirection(directions::DOWN);
                        floor=*downMax.begin();
                        downMax.erase(downMax.begin());
                    }
                    
                }
                else if(dir==directions::DOWN){
                    if(!downMax.empty()){
                        floor=*downMax.begin();
                        downMax.erase(downMax.begin());
                    }
                    else{
                        ec->setDirection(directions::UP);
                        floor=*upMin.begin();
                        upMin.erase(upMin.begin());
                    }
                }
                else{
                    if(!upMin.empty()){
                        ec->setDirection(directions::UP);
                        floor=*upMin.begin();
                        upMin.erase(upMin.begin());
                    }
                    else{
                        ec->setDirection(directions::DOWN);
                        floor=*downMax.begin();
                        downMax.erase(downMax.begin());
                    }
                }
                lock.unlock();
                ec->moveToFloor(floor);
            }
        }

        elevator* getcar(){return ec;}

        int getload(){
            unique_lock<mutex>lock(mx);
            return upMin.size()+downMax.size();
        }

        ~ElevatorController(){
            unique_lock<mutex> lock(mx);
            stop = true;   
            lock.unlock();
            cv.notify_one();

            if(worker.joinable()){
                worker.join();
            }
        }

};