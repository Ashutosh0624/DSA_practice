#include<iostream>
#include<string>
using namespace std;
class Student{
    public:
        virtual void getStudentInfo() const = 0;  // pure virtual function
        
        // Constructor
        Student(string name, int age, string address, string department)
            : name{name}, age{age}, address{address}, department{department} {} 
        
        // Destructor , under public section.
        /* 
          Destructor under public section allows normal deletion of objects.
          Private: Prevents deletion except through specidfic methods, useful in certain design patterns.
          Protected Destructor : Ensures objects can only be deleted through derived class destructors
        */
        virtual ~Student() {}
}