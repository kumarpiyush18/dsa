#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<bool>&visited,int s){
    visited[s]=true;

    cout<<s<<" ";

    for(auto x: adj[s]){ // adj[s] --> vector<int>
        if(!visited[x]){
            dfs(adj,visited,x);
        }
    }
}


void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V=4; //cin>>V; // Number of vertex

    vector<int>adj[V];  // array of vector  index(i)/vertex(i) -> holds all the edges which is adjacent to it

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,2,3);  

//      0
//     / \
//    /   \
//   1-----2-----3
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(adj,visited,0);
        }
    }
    
    

}