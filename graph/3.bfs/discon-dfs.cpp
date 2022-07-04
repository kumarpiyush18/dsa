#include<bits/stdc++.h>
using namespace std;

// signature of dfs function
void bfs(vector<int>adj[],vector<int>&visited,int s){
     visited[s]=true;

    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<< u << " ";
        for(auto v : adj[u]){
            if(!visited[v]){
                q.push(v);
            visited[v]=true;
            }
            
        }
    }
}

void disBFS(vector<int>adj[],int V){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            //call stndard dfs function 
            bfs(adj,visited,i);
        }
    }
}
