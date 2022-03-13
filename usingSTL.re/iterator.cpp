#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    // for(int i =0; i<v.size(); i++){
    //     cout << v[i] << " ";
    // }
    //iterator 사용하기
    //vector<int>::iterator it = v.begin(); auto를 사용
    //auto it = v.begin(); //auto는 자동으로 맞춰준다.
    //for(; it!=v.end(); it++) // 이걸 더 줄일 수 있다.
    //for(auto& it : v) //이렇게 iterator를 auto reference로 사용
    for(int it : v) //최종 외워라!!!
        cout << it <<" ";  
}