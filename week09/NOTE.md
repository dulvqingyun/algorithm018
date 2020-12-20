不同路径II的状态转移方程
if(obstacleGrid[i][j]==0)
    dp[i][j] = dp[i-1][j] + dp[i][j-1];
