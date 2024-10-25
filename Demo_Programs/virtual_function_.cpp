#include<iostream>
#include<string>
using namespace std;
/*
   Virtual function: 
   Important concepts when dealing with inheritance and polymorphosim 
   Declared in the base class but will be overridden by the child class 
*/
class Base{
    public:
        virtual void show(){
            cout<<"Base class show function called :"<<endl;
        }

        ~virtual ~Base(){} // virtual destructor

};
class Derived : public Base{
    public: 
        void show() override {
            cout<<"Derived class show function called "<<endl;
        }
};