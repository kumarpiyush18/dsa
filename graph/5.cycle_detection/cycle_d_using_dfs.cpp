#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int s, vector<bool>&visited,vector<int>adj[],int parent=-1){
    visited[s]=true;

    for(auto x : adj[s]){
        if(!visited[i]){
            if(checkCycle(x,visited,adj,s)){
                return true;
            }
            else if(x != parent){
                return true;
            }
        }
    }
    return false;
}



bool  isCycle(int V,vector<int>adj[]){

    vector<bool>visited(V+1,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkCycle(i,visited,adj,-1)){
                return true;
            }
        }
    }

    return false;
}
