#include<iostream>
#include<string>
using namespace std;
class University{
    public:
        virtual void getUniInfo() const;
        void getName() const;
        void getAddress() const;
        void getYoE() const;
        University(string name, string address, int YoE)
            : name{name}, address{address}, YoE{YoE} {}
    private:
        string name;
        string address;
        int YoE;
};
void University::getUniInfo() const{
    cout<<"Name of the University :"<<name<<endl;
    cout<<"Address : "<<address<<endl;
    cout<<"Year of establishment : "<<YoE<<endl;
}
void University::getName() const{
    cout<<name;
}
void University::getAddress() const{
    cout<<address;
}
void University::getYoE() const{
    cout<<YoE<<endl;
}
class Student: public University{
    public:
        void getUniInfo() const override { // override keyword is optional, but recommended to write
            University::getName();
            cout<<endl;
            University::getAddress();
            cout<<endl;
            University::getYoE();
            cout<<endl;
            cout<<"College name: "<<cname<<endl;
            cout<<"Department : "<<department<<endl;
        }

        Student(string name, string address, int YoE, string cname, string department)
            : University(name, address, YoE), cname{cname}, department{department} {}  

    private:
        string cname;
        string department;
};
int main()
{   University *bptr = nullptr;
    Student s1{"MIT", "Cambridge, USA",1861, "Ashutosh", "ECE"};
    bptr = &s1;
    bptr->getUniInfo();
    return 0;
}
