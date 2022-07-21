#include<bits/stdc++.h>
using namespace std;


// a graph that can be colored exactly with two color such that no two adjacent node has same color

// observation:
 // - if a graph has a cycle with odd number of length then its never be bipartite
 // if a graph that doesn't have any odd length cycle its a bipartite graph
// here we color exact opposite color of previous node whenever we travers a node

bool bfshelper(int s,vector<int>adj[],vector<int>&color){
    color[s]=1;

    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto x : adj[u]){
            if(color[x]==-1){
                color[x]=1-color[u];
                q.push(x);
            }
            else if(color[x]==color[u]){
                return false;
            }
        }
    }
    return true;
}


 bool isBipartiteGraph(int V, vector<int>adj[]){

    vector<int>color(V+1,-1);

    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(bfshelper(i,adj,color)){
                return true;
            }
        }
    }
    return false;
 }