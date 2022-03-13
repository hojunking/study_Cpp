#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>&v){
int s =0;
    for(int i=0; i<v.size(); i++){ //v.size()를 하면 vector의 인덱스 크기
        s+=v[i];
    }
    for(int i=0; i<v.size(); i++){
        v[i]=i*10; //call by reference이기 때문에 함수에서 값 변경한다.
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i =0 ; i <n; i++){
        cin >> v[i];
    }
    
    cout << sum(v) << "\n";
    for(int i =0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
}