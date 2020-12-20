class Solution {
public:
    string longestPalindrome(string s) {

       int sz=s.size();
        if(sz<2) return s;
        int start(0),end(0);
        vector<vector<bool>> dp(sz,vector<bool>(sz,0));
        for(int k=0;k<sz;k++) dp[k][k]=true;
        for(int i=1;i<sz;i++){
            for(int j=0;j<i;j++){
                if(i-j==1&&s[i]==s[j]) dp[j][i]=true;
                else{
                    if(s[j]==s[i]) dp[j][i]= dp[j+1][i-1];
                }
                if(dp[j][i]&&(i-j)>(end-start)) {end=i;start=j;}
            }
        }

        return s.substr(start, end-start+1);

    }
};