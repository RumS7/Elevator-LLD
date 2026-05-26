#include "models/building.cpp"
#include "models/ExternalButton.cpp"
#include "models/elevator.cpp"
#include "models/ElevatorController.cpp"
#include "models/floor.cpp"
#include "models/InternalButton.cpp"
#include "models/ElevatorScheduler.cpp"
#include "strategy/LeastBusy.cpp"
#include "strategy/NearestElevator.cpp"
#include "strategy/SelectionStrategy.cpp"
#include<thread>
#include<chrono>

using namespace std;
int main(){
    elevator* e1=new elevator(1);
    elevator* e2=new elevator(2);

    ElevatorController* ec1=new ElevatorController(e1);
    ElevatorController* ec2=new ElevatorController(e2);

    InternalButton* ib1=new InternalButton(ec1);
    InternalButton* ib2=new InternalButton(ec2);

    ElevatorScheduler* es=new ElevatorScheduler({ec1,ec2});
    es->addStrategy(new NearestElevator());

    building* b=new building(5,es);


    floors* f1=b->getfloor(1);
    floors* f3=b->getfloor(3);
    floors* f4=b->getfloor(4);

    ec1->start();
    ec2->start();

    f1->pressUP(4);
    ib1->press(2);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    f3->pressDOWN(1);
    ib2->press(4);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    f4->pressDOWN(3);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    ib1->press(0);
    std::this_thread::sleep_for(std::chrono::seconds(15));
    
}