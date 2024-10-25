#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
        string name;
        int age;
        string address;
    public:
        Student(){cout<<"empty constructor"<<endl   ;} // Default constructor 
        Student(string name, int age, string address)
            : name{name}, 
              age {age}, 
              address {address} {}
        
        void getDetails() const;
        void setDetails(string name, int age, string address);;

        // copy constructor 

        // destructor 

};
void Student::getDetails() const{
    cout<<"Name : "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Address :" <<address<<endl;
}
void Student::setDetails(string name, int age, string address)
{
    this->name = name;
    this->age = age;
    this->address = address;
}
int main()
{   

    Student s2;  // executing the constructor with empty parameter // default constructor
    Student s1{"Ashutosh", 31, "Singrauli"};
    s1.getDetails();
    s1.setDetails("Ashish", 19, "Singapore");
    s1.getDetails();
    return 0;
}