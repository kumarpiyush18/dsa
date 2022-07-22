#include<bits/stdc++.h>
using namespace std;

// shortest distance from source to destination







int shortestDistance(int V,vector<int>adj[],int s){

    
    vector<int>dist(V+1,INT_MAX);

    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        
        int u = q.front();
        q.pop();
        for(auto x : adj[u]){
            if( dist[u]+1<dist[x]){
                dist[x]=dist[u]+1; // update the array with the new distance
                q.push(x);
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<endl;
    }
    
}



