#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<string>
using namespace std;

class Node{
    public:
    std::string name;
    std::list<std::string>nbrs;

    Node(std::string name) : name{name} {}
};

class Graph{
    std::unordered_map<std::string, Node*>map;

    public:
    Graph(std::vector<std::string>cities){
        for(auto city: cities){
            map[city] = new Node(city);
        
    }
    }

    void addEdge(std::string x, std::string y, bool undir = false){
        map[x]->nbrs.push_back(y);
        if(undir){
            map[y]->nbrs.push_back(x);
        }
    }
    void printAdjList() const{
        for(const auto& citypair: map){
            auto city = citypair.first;
            Node *node = citypair.second;

            for(auto nbr: node->nbrs){
                cout<<city<<"-->"<<nbr<<endl;
            }
            }
        }
};

int main(){
    std::vector<std::string>cities = {"Delhi", "Mumbai", "Kolkata", "Chennai"};
    Graph g(cities);
    g.addEdge("Delhi", "Mumbai");
    g.addEdge("Mumbai", "Kolkata");
    g.addEdge("Kolkata", "Chennai");
    g.addEdge("Chennai", "Delhi", true);
    g.printAdjList();
    return 0;
}

