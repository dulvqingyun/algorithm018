class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m)   return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for( int i =0; i<m; i++){
            for ( int j =0; j< n; j++){
                if(i ==0 && j ==0 ){
                    dp[i][j] = obstacleGrid[i][j]==1? 0:1;
                }
                if(i==0 && j!=0){
                    dp[i][j] = obstacleGrid[i][j]==1? 0:dp[i][j-1];
                }
                if(i!=0 && j==0){
                    dp[i][j] = obstacleGrid[i][j]==1? 0:dp[i-1][j];
                }
                else if(i!=0 && j!=0) {
                    dp[i][j] = obstacleGrid[i][j]==1? 0:(dp[i-1][j] + dp[i][j-1]);
                }
            }
        }     
        return dp[m-1][n-1];
    }
