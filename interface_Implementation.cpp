#include<iostream>
#include<string>
using namespace std;
class Vehicle{
    public:
        // Interface class for vehicle
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void drive() = 0;

    // virtual destructor
    virtual ~Vehicle(){}
};
class Car: public Vehicle{
    public:
        Car(string make, string model, int purchaseYear)
         :make{make}, model{model}, purchaseYear{purchaseYear}{}
        
        void start();
        void stop();
        void drive();

    private:
        string make;
        string model;
        int purchaseYear;
};
void Car::start(){
    cout<<"Car is in start mode."<<endl;
}
void Car::stop(){
    cout<<"car is in stop mode"<<endl;
}
void Car::drive(){
    cout<<"Car is in driving."<<endl;
}