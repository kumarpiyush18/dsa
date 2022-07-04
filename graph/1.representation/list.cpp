#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>adj[],int V){
    
    for(int i=0;i<V;i++){
        vector<int>data = adj[i];
        for(int x : data){
            cout<<x << " "; 
        }
        cout<<endl;
    }
}


int main(){
    int V=4; //cin>>V; // Number of vertex

    vector<int>adj[V];  // array of vector  index(i)/vertex(i) -> holds all the edges which is adjacent to it

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,2,3);  

//      0
//     / \
//    /   \
//   1-----2-----3

print(adj,4);

}