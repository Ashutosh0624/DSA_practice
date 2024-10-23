#include<iostream>
using namespace std;

bool isSorted(int *arr, int n){
    if(n ==0 || n==1) return true;  // base case

    if(arr[0] > arr[1]) return false;  // 1st case : processing 

    bool ans = isSorted(arr+1, n-1);  // recursive call

    return ans;
}

// method 2 : two pointer approach

bool isSortedArr(int *arr, int n){
    for(int i=0, j=i+1; i<n; i++, j++){
        if(arr[i] > arr[j]){
            return false;
        }
    }
    return  true;
}

int main(){
    int  arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(int);

    bool res = isSorted(arr, n);

    cout<<isSortedArr(arr, n)<<endl;

    cout<<res<<endl;
    return 0;
}