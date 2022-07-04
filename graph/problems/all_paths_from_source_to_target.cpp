 // 797. All Paths From Source to Target [leetcode]
 
 void dfs(vector<vector<int>>& graph,vector<vector<int>> &ans, vector<int>&path ,int s){
        path.push_back(s);
        if(s==graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto x : graph[s]){
                dfs(graph,ans,path,x);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        
        dfs(graph,ans,path,0); // call the dfs function
        
        return ans;
    }