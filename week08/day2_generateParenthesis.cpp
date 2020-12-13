class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n<=0) return {};
        
        vector<vector<string>>dp(n+1);
        dp[0].push_back("");
        dp[1].push_back("()");
        for(int i =2; i<n+1; i++){   
            for(int j =0; j<i; j++){
                for(string p: dp[j]){
                    for(string q: dp[i-j-1]){
                        string str = "(" +p +")"+q;
                        dp[i].push_back(str);        
                    }
                }
            }
        }
        return dp[n];
    }
};