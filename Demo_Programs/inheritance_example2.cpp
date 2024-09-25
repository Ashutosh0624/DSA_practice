#include<iostream>
#include<string>
using namespace std;
/*
In C++, when a base class has private members, those private members are not directly accessible by derived (child) classes.
Only public and protected members of the base class are accessible to derived classes.

Note: Only public and protected members of the base class can be accessed by the child class
*/
class Vehicle{
    private:
        string model;
        string manufacturer;
    
    public:
        string getModelName() const;
        string getManufacturerName() const;
        Vehicle(string model, string manufacturer)
            : model{model},
              manufacturer{manufacturer}{}
};
string Vehicle::getModelName() const{
    return model;
}
string Vehicle::getManufacturerName() const{
    return manufacturer;
}
class Car: public Vehicle{
    private:
        int doors;
        int price;
    public:
        // access private member of the base class via getter and setter
        string CarModel = getModelName();
        string CarManufacturer = getManufacturerName();
        void getCarInfo() const;
        Car(string model, string manufacturer, int doors, int price) 
            : Vehicle(model, manufacturer), 
              doors{doors}, price{price} {}
};
void Car::getCarInfo() const {
    Vehicle::getModelName();
    Vehicle::getManufacturerName();
    cout<<"Car Model : "<<CarModel<<endl;
    cout<<"Car manufacturer :"<<CarManufacturer<<endl;
    cout<<"Doors : "<<doors<<" "<<"Price of the car :"<<price<<endl;
}
int main(){
    Vehicle v1 {"4 wheeler", "Maruti"};

    Car c1{v1.getModelName(),v1.getManufacturerName(), 4,  400000};
    c1.getCarInfo();
    return 0;
}