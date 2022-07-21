#include<bits/stdc++.h>
using namespace std;




bool dfsHelper(int s,vector<int>adj[],vector<int>&color){
    if(color[s]==-1)
    color[s]=1;

    for(auto x : adj[s]){
        if(color[x]==-1){
            color[x]=1- color[s];
            if(!dfsHelper(x,adj,color)){
                return false;
            }
            else if (color[x]==color[s]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V,vector<int>adj[]){

    vector<int>color(V+1,-1);

    for(int i=0;i<V;i++){
        if(!dfsHelper(i,adj,color)){
            return false;
        }
    }
    return true;
}