#include<bits/stdc++.h>
using namespace std;

/*
Algorithm :


*/
void dfs(vector<int>adj[],vector<bool>&visited,stack<int>&st,int s){
    visited[s]=true;
    for(auto x: adj[s]){
        if(!visited[x]){
            dfs(adj,visited,st,x);
        }
    }
    st.push(s);
    
}
vector<int>topoSort(vector<int>adj[],int V){

    stack<int>st;

    vector<bool> visited(V+1,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(adj,visited,st,i);
        }
    }
    while(!st.empty()){
        int u = s.top();
        ans.push_back(u);
        s.pop();
    }

    return ans;
}