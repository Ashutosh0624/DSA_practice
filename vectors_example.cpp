#include<iostream>
#include<vector>
using namespace std;
int main(){

    // declaration of vector
    vector<int> vec; // size 0
    vector<int>arr{1,2,3,4,5,6,7};
    vector<int>arr1(3, 0); // creates vector of 3 numbers with values 0
    vector<char>arr3{'a', 'b', 'c'};
    for(int &x: arr){
        cout<<x<<"  ";
    }
    for(int x:arr3){
        cout<<x<<" ";
    }
    cout<<arr.size()<<endl;
    for(int i = 0; i<5; i++){
        vec.push_back(i);
    }
    for(int x: vec){
        cout<<x<<"  ";
    }
        // vector functions
    /*
    
    */
   cout<<endl;
   cout<<vec.front()<<endl;
   cout<<vec.back()<<endl;
   cout<<vec.at(2)<<endl;
    return 0;
}