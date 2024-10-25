#include<iostream>
#include<string>
using namespace std;
class Vehicle{
    public:
        void displayVehicle_info() const;
        Vehicle(const string& manufacturer, const string& model)   
            : manufacturer{manufacturer},
              model{model} {}
    private:
        string manufacturer;
        string model;

};
void Vehicle::displayVehicle_info()const{
    cout << "Manufacturer: " << manufacturer << " " << "Model: " << model << endl;
}

class Engine {
    public:
        void displayEngine_info() const;
        Engine(const int& horsepower, const string& engine_type)
            : horsepower{horsepower},
              engine_type{engine_type} {}   
    private:
        int horsepower;
        string engine_type;
        
};
void Engine::displayEngine_info() const{
     cout<<"Engine "<<horsepower<<"  HP "<<" "<<" Type"<< engine_type <<endl;
}

class Car: public Vehicle, public Engine {
    public:
        void displayCar_info() const;
        Car(const string& manufacturer, const string& model, const int& horsepower, const string& engine_type, const int& doors)
            : Vehicle(manufacturer, model), Engine(horsepower, engine_type), doors{doors} {}
    
    private:
        int doors;

};
void Car::displayCar_info() const{
   
   Vehicle::displayVehicle_info();
   Engine::displayEngine_info();
   cout<<"Doors : "<<doors<<endl;

}
int main()
{  
  cout<<"Build successfully"<<endl;
  return 0;
}
