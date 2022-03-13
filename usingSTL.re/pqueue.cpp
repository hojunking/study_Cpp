#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    //priority_queue<int> pq; //디폴트는 내림차순이다.
    //priority_queue<int, vector<int>, greater<int>> pq; //container(vector), greater<int>
    //greater는 오름차순정렬이다.
    //less<int>는 내림차순
    priority_queue<int, vector<int>> pq; //내림차순은 디폴트 
    for(int i =0; i <n; i++){
        int x;
        cin >> x;
        pq.push(x); //큐에 푸시합니다.
    }
    while(!pq.empty()){
        cout << pq.top() <<" ";
        pq.pop();
    }
    cout <<"\n";
}