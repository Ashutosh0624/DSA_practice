#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int * sortArray(int *arr, int size){
    // in every iteration 
   for(int i = 0; i<size - 1; i++){
       // as there are n elements, then n-1 passes have to be performed
       for(int j = 0; j<size - 1 - i; j++)
       // in every pass comparison should reduce
       if(arr[i] > arr[j + 1]){
        swap(arr[i], arr[j + 1]);
       }
   }
   return arr;
}

int main()
{
    int arr[] {5,2,6,9,10};
    int size = sizeof(arr)/sizeof(int);
    int *newArr = sortArray(arr, 5);
    for(int i = 0; i<(size); i++){
        cout<<*(arr + i)<<" ";
    }
    cout<<endl;
    return 0;


}