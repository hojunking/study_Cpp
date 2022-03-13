#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct mycomapre { //연산자 오버로딩
    bool operator()(string s1, string s2){
        //return s1.length() > s2.length(); //각 문자열 길이 비교하기 비교 원소개수를 3개를 보내면 작동 안된다.
        return s1 > s2;
    }
};

int main() {
    int n;
    cin >> n;
    //priority_queue<string, vector<string>> pq; //문자열 디폴트 확인 알파벳순
    //priority_queue<string, vector<string>,greater<string>> pq; //알파벳 오름차순
    priority_queue<string, vector<string>,mycomapre> pq;
    for(int i =0; i <n; i++){
        string x;
        cin >> x;
        pq.push(x); //큐에 푸시합니다.
    }
    while(!pq.empty()){
        cout << pq.top() <<" ";
        pq.pop();
    }
    cout <<"\n";
}