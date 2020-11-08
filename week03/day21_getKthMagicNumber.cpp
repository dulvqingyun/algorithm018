class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int>dp(k,0);
        dp[0]=1;
        int l3(0),l5(0),l7(0); //指针
        for(int i=1;i<k;i++){
            dp[i]= min(min(dp[l3]*3,dp[l5]*5),dp[l7]*7);
            if(dp[i]==dp[l3]*3)
                l3++;
            if(dp[i]==dp[l5]*5)
                l5++;
            if(dp[i]==dp[l5]*5)
                l7++;
        }
        return dp[k-1];
    }
};