#include<bits/stdc++.h>
using namespace std;


int parent[100000];
int rank[10000];


void makeset(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}


int findParent(int node){
    if(parent[node]==node){
        return node;
    }

    return parent[node]=findParent(parent[node]); // path compression
}


void union(int u,int v){
    u = findParent(u);
    v = findParent(v);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }

}


int main(){
    makeSet();
    int m; cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        union(u,v);
    }
    // 2 and 3 belong to same component or not
    if(findParent(2)!=findParent(3)){
        cout<<"They belong to different component";
    }
    else{
        cout<<"they belong to same component";
    }
}