/*
Given two strings s & t. 
t string has 1 char extraa
Objective is to find the difference between the two and return the character 
*/
#include<iostream>
#include<string>
#include<unordered_map>
// approach 1
char findTheDifference(std::string s, std::string t){

    char res = '';
    for(int i=0; i<s.size(); i++){
        res ^=s[i];
    }
    for(int i=0; i<t.size(); i++){
        res ^=t[i];
    }
    return res;
}

// approach 2

char findtheDiffernce(std::string s, std::string t){
    std::unordered_map<char, int>map;
    for(int i=0; i<s.size(); i++){
        map[s[i]]++;
    }
    for(auto c: t){
        if(map.find(c) == map.end() || map[c] == 0){
            return c;
        }
        map[c]--;
        }
        return ' ';
    }