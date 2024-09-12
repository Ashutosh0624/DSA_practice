#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int>arr{10, 5, 34, 78, -8};

    // sort function
    arr.sort();

    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;   
}
