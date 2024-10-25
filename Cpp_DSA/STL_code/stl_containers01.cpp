/*
  Vector functions : 
        1) vector.push_back(val) : inserts value from the end, append values 
        2) vector.emplace_back(2) : similar to push back, faster than the the push back 
        2) vector.pop_back() : removes the last value
        3) vector.front() : returns the first value
        4) vector.end() : returns the last element


*/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>vec{15,2,30,-4,5};
    for(int x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    sort(vec.begin(), vec.end(), greater<int>());
    for(int x: vec){
        cout<<x<<" ";
    }
    // vector of pair
    vector<pair<int, int>>vec2;
    vec2.emplace_back(12, 13);
    cout<<endl;


    // different ways of declaring vector
    vector<int>vec4(5, 100); // initializes the vector vec of 5 elements with value 100 each.
    vector<int>vec3(6); //vector with 6 elements with some garbage value

    // copy 
    vector<int>v2(vec); 

    // iterator 
    vector<int>::iterator it = vec.begin(); // the iterator is pointing to the first element memory address.
    for(it = vec.begin(); it<vec.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout<< *(it)<<" ";
    }

    for(auto it = vec.begin(); it != vec.end(); it++){  // stl automatically defines the datatype, no need to define the iterator datatype explicitly.
        cout<<*(it)<<" ";
    }
    cout<<endl;
    // for each loop
    for(auto x: vec){
        cout<<x<<" ";
    }

    // deletion in vector
    vec.erase(vec.begin() + 1); // vec.erase(takes memory address to delete) , this to delete single element
    cout<<endl;
    for(auto x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    // delete multiple elements
    vec.erase(vec.begin()+1, vec.begin() + 3);  // erase(start address, end address)
    for(auto x: vec){
        cout<<x<<" ";
    }
    cout<<endl;
    //insert function
    vec.insert(vec.begin(), 400);
    vec.insert(vec.begin() + 1, 2, 5); // syntax : insert(start address, number of elements to be inserted, element to be inserted)
    for(auto x: vec){
        cout<<x<<" ";
    }
    // inserting a vector into another vector
    vector<int>copy {50, 80};
    vec.insert(vec.begin() + 1, copy.begin(), copy.end());
    cout<<endl;
    for(auto x: vec){
        cout<<x<<" ";
    }
    cout<<vec.size()<<endl; // returns the number of elements in the vec
    cout<<vec.capacity()<<endl; // returns the actual memory allocated currently
    vec.pop_back();
    vec.clear(); // erases the entire vector
    vec.empty(); 

    return 0;
}