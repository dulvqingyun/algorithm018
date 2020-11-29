    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        int result=0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        for(int j=0; j<n;j++){
            if(i==0||j==0) dp[i][j]= matrix[i][j]=='0'?0:1;
            else if(matrix[i][j]=='1'){
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]),dp[i-1][j-1])+1;
            }
            result = max(result,dp[i][j]);
        }
        return result*result;

    }