void convert(vector<vector<char>>&board,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='B')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void dfs(vector<vector<char>>&board,int n,int m,int i,int j){
        
        if(i<0 || i >=n) return;
        if(j <0 || j>=m) return;
        if(board[i][j]!='O') return;
        
        board[i][j]='B';
        
        dfs(board,n,m,i+1,j);
        dfs(board,n,m,i-1,j);
        dfs(board,n,m,i,j+1);
        dfs(board,n,m,i,j-1);
        
        
    }
    
    
    
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m= board[0].size();
        
        // traverse on the boundary and mark all the connected component as 'B'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
               if((i==0 || i==n-1 || j==0 || j==m-1)&&board[i][j]=='O'){
                dfs(board,n,m,i,j);
                } 
            }
        }
        
        // remaing zero will be the region surrounded by the x call the convert function to 
        // change B --> O and 'O' to X
        convert(board,n,m);
        
    }