#include<bits/stdc++.h>
using namespace std;


bool helper(int s, vector<int>adj[],vector<bool>&vis,vector<bool>&dfsvis){
    vis[s]=1;
    dfsvis[s]=1;

    for(auto x: adj[s]){
        if(!vis[x]){
            if(helper(x,adj,vis,dfsvis)){
                return true;
            }

        }
        else if(dfsvis[x]){
            return true;
        }
    }
    dfsvis[s]=false;
    return false;
}



bool hasCycle(int V,vector<int>adj[]){

    vector<bool>vis(V+1,false);
    vector<bool>dfsvis(V+1,false);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(helper(i,adj,vis,dfsvis)){
                return true;
            }
        }
    }
    return false;
}