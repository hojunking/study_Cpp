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
    v.push_back(5); //v.end()에 값 5를 넣습니다.
    
    sort(v.begin(),v.end()); //정렬 알고리즘 <algorithm>
    for(int it : v) //최종 외워라!!!
        cout << it <<" ";  
}