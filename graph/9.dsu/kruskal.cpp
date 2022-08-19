#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int w;

    node(int first,int second,int weight){
            u = first;
            v= second;
            w = weight;
    }

};


bool comp(node a,node){
    return a.wt < b.wt;
}


int findParent(int u, vector<int>&parent){
    if(u == parent[u]){
        return u;
    }

    return parent[u]=findParent(parent[u],parent);
}

void unionn(int u,int v,vector<int>&parent,vector<int>&rank){

    u = findParent(u,parent);
    v = findParent(v,parent);

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
    int N,m;
    cin>>N>>m;
    vector<node>edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }

    sort(edges.begin(),edges.end(),comp);

    vector<int>parent(N);
    for(int i=0;i<N;i++){
        parent[i]=i;
    }

    vector<int>rank(N,0);
    int cost =0;
    vector<pair<int,int>>mst;
    for(auto it : edges){
        if(findParent(it.v,parent)!=findParent(it.u,parent)){
            cost+=it.w;
            mst.push_back(make_pair(it.u,it.v));
            unionn(it,u,it.v,parent,rank);

        }
    }

    cout<<"Cost of mst : "
    cout<<cost<<endl;

    for(auto x : mst){
        cout<<x.first <<"--"<<x.second<<endl;
    }
}