#include<bits/stdc++.h>
using namespace std;

// topological sort : here we print the less dependency vertex first 

// those which has lesser indegree write first (also known as khan's algorithm)

/*
Algorithm:
1. store indegree of each vertex 
2. create a queue
3. store '0's indegree vertex in queue
4. while(queue is not empty)
    5. u= q.front(), q.pop()
    6. print u
    7. for every adjancent V of u:
        8. reduce indegree of V
        9.if indegree of V is zero add it to the queue
*/

vector<int> topoSort(int V, vector<int>adj[]){
    vector<int> ans;
    queue<int>q;
    vector<int>indegree(V,0); //fill the vector with 0
    for(int i=0;i<V;i++){
        vector<int>data = adj[i];
        for(auto x: data){
            indegree[x]++;
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto x: adj[u]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    return ans;
}

