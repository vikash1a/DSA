#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        void test(){
            //bfs
            // vector<vector<int>> adj = createGraph();
            // vector<int> bfsV = bfs(adj);
            // print(bfsV);
            //

            //dfs
            vector<vector<int>> adj = createGraph();
            vector<int> dfsV = bfs(adj);
            print(dfsV);
            //
            return ;
        }
        void print(vector<int> v){
            for(int i:v){
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        //create graph
        vector<vector<int>> createGraph(){
            vector<vector<int>> vvg ;
            vvg.push_back({1,2});
            vvg.push_back({2});
            vvg.push_back({0,3});
            vvg.push_back({3});
            return vvg;
        }
        //

        //bfs
        vector<int> bfs(vector<vector<int>> adj){
            vector<int> bfsV;
            vector<int> visited(adj.size(),false);
            queue<int> qu;
            qu.push(0);
            visited[0]=true;
            while(!qu.empty()){
                int temp = qu.front();
                bfsV.push_back(temp);
                qu.pop();
                for(int i=0;i<=adj[temp].size()-1;i++){
                    if(!visited[adj[temp][i]]){
                        qu.push(adj[temp][i]);
                        visited[adj[temp][i]] = true;
                    }
                }
            }
            return bfsV;
        }

        //dfs
        vector<int> dfs(vector<vector<int>> adj){
            vector<int> dfsV;
            vector<int> visited(adj.size(),false);
            visited[0]=true;
            dfsHelper(adj,0,visited,dfsV);
            return dfsV; 
        }
        void dfsHelper(vector<vector<int>> adj, int k,vector<int> visited,vector<int>& dfsV){
            for(int i=0;i<=adj[k].size()-1;i++){
                if(!visited[adj[k][i]]){
                    visited[adj[k][i]] = true;
                    dfsV.push_back(adj[k][i]);
                    dfsHelper(adj,adj[k][i],visited,dfsV);
                }
            }
            return;
        }
        //

};

int main(){
    cout<<"Hello World\n";
    Graph graph;
    graph.test();
    return 0;
}