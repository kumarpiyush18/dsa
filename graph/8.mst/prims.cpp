#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<n;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    int key[n];
    int parent[n];
    bool mstSet[n];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX,parent[i]=-1,mstSet[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n-1;count++){
        int mini =INT_MAX,u;
        for(int v=0;v<n;v++){
            if(mstSet[v]==false && key[v]<mini){
                key[v]=mini,u=v;
            }
        }
        mstSet[u]=true;
        for(auto it:adj[u]){
            int v = it.first;
            int wt = it.second;
            if(mstSet[v]==false && wt <key[v]){
                key[v]=wt,parent[v]=u;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<< parent[i]<<"-->"<<i;
    }
}