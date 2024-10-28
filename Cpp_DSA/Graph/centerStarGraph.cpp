#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// approach 1 : O(1) time complexity
int findCenter(const vector<vectoe<int>>&edges){
    vector<int>first = edges[0];
    vector<int>second = edges[1];
    if(first[0] == second[0] || first[0] == second[1]){
        return first[0];
    }
    return first[1];
}

// approach 2:
int findCenterGraph(const vector<vector<int>>&edges){
    std::unordered_map<int, int>degrees;
    
    for(const auto& node: edges){
        int u = node[0];
        int v = node[1];
        
        degrees[u]++;
        degrees[v]++;
    }
    for(auto &it: degrees){
        if(it.second == edges.size()){
            return it.first;
        }
    }
    return -1;
}