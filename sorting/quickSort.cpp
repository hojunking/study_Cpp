#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&s, int left, int right){
    int pivot = s[left];
    int low = left-1, high =right;
    

}

void quick_sort(vector<int>&s,int left, int right){
    if(left < right){
        int q = partition(s,left, right);
        quick_sort(s,left, q-1);
        quick_sort(s,q+1,right);
    }
}

int main(void){
    int n;
    cin >>n;
    vector<int> s(n);
    for(int i =0; i<n;i++){
        cin >> s[i];
    }
    quick_sort(s,0,n);
}