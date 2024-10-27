#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityEle(std::vector<int>&nums){
    // brute forc
    for(int i=0; i<nums.size(); i++){
        int count = 0;
        for(int  j = 0; j<nums.size(); j++){
            if(nums[i] == nums[j]){
                count++;
            }
            }
            if(count >nums.size()/2){
                return nums[i];
            }
        }

    }

int majorityElement(std::vector<int>&nums){
    int n = nums.size();
    std::unordered_map<int,int>count;
    for(int i=0; i<n; i++){
        count[nums[i]]++;
    }
    for(const auto& it:count){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}

int main(){
    std::vector<int>nums = {2,2,2,2,2,1,4,1};
    int ans = majorityEle(nums);
    std::cout<<"The majority element is: "<<ans<<std::endl;
    int ans2 = majorityElement(nums);
    std::cout<<"The majority element is: "<<ans2<<std::endl;
    return 0;
}
