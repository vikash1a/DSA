#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v){
    for(int k: v){
        cout<<k<<" ";
    }
    cout<<endl;
}
void heapifyHelper(vector<int>& v, int i, int n){
    int l = 2*i+1, r = 2*i+2;
    if(r>n)return;
    if(v[i]<v[l] && v[l]>v[r]){
        swap(v[i],v[l]);
        heapifyHelper(v,l,n);
    }
    else if(v[i]<v[r]){
        swap(v[i],v[r]);
        heapifyHelper(v,r,n);
    }
    return;
}
void heapify(vector<int>& v){
    int n = v.size()-1;
    for(int i=n/2-1; i>=0; i--){
        heapifyHelper(v,i,n);
        print(v);
    }
}

int main(){
    cout<<"hello world"<<endl;
    vector<int> v = {4,2,6,3,7,5,4,32,5};
    heapify(v);
    // print(v);
    return 0;
}