#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;
int main(){
    list<int> ls;
    stack<int>st;
    st.push(3);
    st.push(5);
    st.push(89);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top();
    cout<<endl;
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.emplace(6);

    cout<<q1.front()<<endl;
    cout<<q1.back()<<endl;
    q1.pop();
    cout<<q1.front()<<endl;

    q1.back() += 4;
    cout<<q1.back();
    cout<<endl;

    // priority queue
    priority_queue<int>pq;

    pq.push(34);
    pq.push(39);
    pq.push(33);
    pq.push(37);
    pq.emplace(56);

    cout<<pq.top()<<endl; // prints 56
    return 0;

    // rest function same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}