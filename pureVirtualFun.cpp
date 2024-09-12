/*
   Pure virtual function : A function that has no implementation in the base class and must be overridden in the derived classes.
   A class that contains atleast one pure virtual function is called Abstract class.
   Note: Abstract classes cant be instantiated on their own and are meant to provide a base for other classses.
   Pure vitual function is declared by equatating virtual fun = 0. This indicates that the function is not implemented in the base class, 
   and must be implemented under derived class.
   Abstract class serves as a blue print for derived classes, forcing them to implement the pure virtual functions. We cant create an instance of the 
   abstract class.
*/
#include<iostream>
#include<string>
using namespace std;
class Shape{
    public: 
        // Pure virtual function
        virtual void draw() const = 0;

        // Regular member function
        void info() const{
            cout<<"This is a shape"<<endl;
        }

        // virtual destructor to ensure proper cleanup
        virtual ~Shape() {}
};

// Derived class

class Circle:public Shape{
    public:
        void draw() const override{
            // Implementing the virtual function
            cout<<"This is the circle"<<endl;
        }
};
// derived class 2
class Rectangle: public Shape{
    public:
        void draw() const override{
            cout<<"This is shape Rectangle"<<endl;
        }
};
int main()
{   
    // create a base clas pointer
    Shape *bptr = new Circle();
    Shape *bptr2 =new Rectangle();
    bptr->draw();
    bptr2->draw();

    //cleanup
    delete bptr;
    delete bptr2;

    return 0;
}
/*
   Key points about abstract classes 

    1) Contains atleast one pure virtual function
    2) Cannot be instantiated
    3) Used as a base class to define a common interface for derived classes

    Usage: 
    Abstract classes and pure virtual functions are useful in designing systems where you want to define
    a common interface for different types of derived classes, ensuring that certain functions are implemented by each derived class.

    When to use :
         Defining Interfaces: When you want to enforce that all derived classes implement specific methods.
         Polymorphism: When you want to achieve runtime polymorphism, allowing different derived classes to be treated uniformly through base class pointers or references.
 
*/