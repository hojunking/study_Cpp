#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    //search 10
    int f;
    cin >> f;
    //vector<int>::iterator it;
    //auto it = v.begin();
    auto it =find(v.begin(),v.end(),f); //find는 iterator를 return한다.
    //if(it != NULL) //iterator의 위치가 end()에 도착했다는 것은 찾지 못했다는 것!! NULL이 아니라
     if(it != v.end()) //iterator type
        cout << "found " << *it <<"!!"; //*it -> iterator가 가르키는 값
    else
        cout << "not found";
}