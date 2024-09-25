#include<iostream>
using namespace std;
class Printer{
    public: 
        void print(int i) {
            cout<<"Printing integer :"<<i<<endl;
        }

        void print(double i){
            cout<<"Printing double : "<<i<<endl;
        }
        void print(const string& s){
            cout<<"String value : "<<s<<endl;
}
};

int main() {
    Printer p;
    p.print(20);
    p.print(10000000.9999);
    p.print("hELLO");
    return 0;
}