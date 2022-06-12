#include <bits/stdc++.h>
using namespace std;


//self tried
// void topologicalSortingUtil(vector<vector<int>> vvg, vector<vector<int>> vvgReverse,
//     vector<bool> &visited, int k, vector<int>& ans,vector<bool> &recStack)
//     {
    
//     if(visited[k]) return;
//     else{
//         recStack[k] = true;
//         for(int i=0;i<=vvgReverse[k].size()-1;i++){
//             if(!visited[vvgReverse[k][i]] && !recStack[vvgReverse[k][i]]){
//                 topologicalSortingUtil(vvg,vvgReverse,visited,vvgReverse[k][i],ans,recStack);
//             }
//         }
//         ans.push_back(k);
//         visited[k] = true;
//         recStack[k] = false;

//         for(int i=0;i<=vvg[k].size()-1;i++){
//             if(!visited[vvg[k][i]] && !recStack[vvg[k][i]]){
//                 topologicalSortingUtil(vvg,vvgReverse,visited,vvg[k][i],ans,recStack);
//             }
//         }
//     }

//     return;
// }

// vector<int> topologicalSorting(vector<vector<int>> vvg){
//     int nv = vvg.size()-1;
//     vector<vector<int>> vvgReverse(nv+1);
//     for(int i=0;i<=nv;i++){
//         cout<<i<<endl;
//         if(vvg[i].size()==0)continue;
//         for(int j=0;j<=vvg[i].size()-1;j++){
//             cout<<j<<"-"<<endl;
//             vvgReverse[vvg[i][j]].push_back(i);
//             // cout<<i<<" "<<j<<" "<<vvg[i][j]<<endl;
//             // cout<<"t";
//         }
        
//     }
//     cout<<"test";
//     vector<bool> visited(nv+1,false);
//     vector<bool> recStack(nv+1,false);
//     vector<int> ans;
//     topologicalSortingUtil(vvg,vvgReverse,visited,0,ans,recStack);

//     return ans;
// }

//gfg

void topologicalSortUtil(vector<vector<int>> vvg, vector<bool>& visited,stack<int>& st,int k){
    visited[k] = true;
    if(vvg[k].size() >=1 ){
        for(int i=0;i<=vvg[k].size()-1;i++){
            if(!visited[vvg[k][i]]){
                topologicalSortUtil(vvg,visited,st,vvg[k][i]);
            }
        }
    }
    
    st.push(k);
    return;
}
vector<int> topologicalSort(vector<vector<int>> vvg, int nv){
    vector<bool> visited(nv+1,false);
    stack<int> st;

    for(int i=0;i<=nv;i++){
        if(!visited[i]){
            topologicalSortUtil(vvg, visited, st,i);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    cout<<"Hello World\n";

    vector<vector<int>> vvg;
    vvg.push_back({});
    vvg.push_back({});
    vvg.push_back({3});
    vvg.push_back({1});
    vvg.push_back({0,1});
    vvg.push_back({0,2});

    vector<int> v = topologicalSort(vvg,5);
    cout<<"topological Sorting :-\n";
    for(int i:v){
        cout<<i<<" ";
    }

    return 0;
}
