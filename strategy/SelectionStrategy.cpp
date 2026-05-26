#include "../enums/directions.cpp"
#include "../models/ElevatorController.cpp"
#pragma once

class SelectionStrategy{
    public:
        virtual ElevatorController* selectElevator(int floor, directions dir,vector<ElevatorController*>ec){};
};