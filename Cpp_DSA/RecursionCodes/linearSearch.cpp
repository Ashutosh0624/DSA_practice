#include<iostream>
using namespace std;

bool linearSearch(int *arr, int  n, int key){
    if(n==0) return false;
    
    if(arr[0] == key) return true;
    
    bool res = linearSearch(arr + 1, n-1, key);
    
    return res;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int key = 10;
    
    bool ans = linearSearch(arr, n, key);
    
    if(ans){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    
    return 0;
}