#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,src;
    cin>>n>>m;

    vector<pair<int,int>> graph[n+1]; // 1-indexed adjacency list for graph
    int a,b,wt;

    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        // pair<node,wt>
        graph[a].push_back(make_pair(b,wt));
        graph[b].push_back(make_pair(a,wt));
    }

    // input the source node
    cin>>src;

    //Algorithm

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // min-headp:
    vector<int>distTo(n+1,INT_MAX); // 1-indexed array for calculating shortest paths;

    distTo[src]=0;

    pq.push(make_pair(0,src)); // {dist,src}

    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int,int>>:: iterator it;

        for(it = graph[prev].begin();it!=graph[prev].end();it++){
            int next = it->first;
            int nextDist = it->second;
            if(distTo[next]>distTo[prev]+nextDist){
                distTo[next]=distTo[prev]+nextDist;
                pq.push(make_pair(distTo[next],next));
            }
        }
    }

    cout<<"The distance from source, " << src <<" , are : \n";
    for(int i=1;i<=n;i++){
        cout<<distTo[i]<<" ";
        cout<<endl;
    }
}

/*
input:
5 6
1 2 2
1 4 1
2 5 5
2 3 4
3 5 1
3 4 3
1

output :
0
2
4
1
5

*/