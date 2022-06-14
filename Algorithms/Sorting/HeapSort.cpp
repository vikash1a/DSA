#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> v){
    int n = v.size()-1;
    for(int i=0;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
}
void heapify(vector<int>& v, int i, int n){
    if(2*i+2 > n)return;
    int l =2*i+1, r = 2*i+2;
    
    // printArray(v);
    if(v[i] < v[l] && v[l] > v[r]){
        swap(v[i],v[l]);
        heapify(v,l,n);
    }
    else if(v[i] < v[r]){
        swap(v[i],v[r]);
        heapify(v,r,n);
    }
    return;
}
void heapSort(vector<int>& v){
    int n = v.size()-1;
    //heapify
    for(int i=0;i<=n/2-1;i++){
        heapify(v,i,n);
    }
    printArray(v);
    cout<<"t\n";
    for(int i=0;i<=n;i++){
        swap(v[0],v[n-i]);
        heapify(v,0,n-i-1);
        printArray(v);
    }
    return;
}

int main()
{
    vector<int> v = { 12, 11, 13, 5, 6, 7 };
  
    heapSort(v);
  
    cout << "Sorted array is \n";
    printArray(v);
}