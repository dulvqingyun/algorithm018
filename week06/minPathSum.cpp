   int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        // vector<vector<int>> path(m, vector<int>(n,0));
        //在原来数组上修改，不用开辟新空间
        
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(i==0&&j==0) 
                    ;
                else if(i==0&&j!=0) 
                    grid[i][j] += grid[i][j-1];
                else if(j==0&&i!=0) 
                    grid[i][j] += grid[i-1][j];
                else 
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                
            }
        }
        return grid[m-1][n-1];

    }