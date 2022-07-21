#include<bits/stdc++.h>
using namespace std;

bool check_cycle(int s,int V,vector<int>adj[],vector<int>&visited){
    visited[s]=true;
    //pair of node,parent
    queue<pair<int,int>>q;
    q.push({s,-1});

    while(!q.empty()){
        auto p = q.front();
        int u = p.first
        int parent = u.second

        for(auto v:adj[u]){
            if(!visited[x]){
                visited[x]=true;
                q.push({x,u});
            }
            else if(parent != x){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V+1,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(check_cycle(i,V,adj,visited)){
                return true;
            }
        }
    }

    return false;
}