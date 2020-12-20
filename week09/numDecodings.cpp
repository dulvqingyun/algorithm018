class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size();
        if(s[0]=='0') return 0;
        vector<int> dp(sz+1,1);
        for( int i =2;i<=sz;i++){
            if(s[i-1]=='0'){
                if(s[i-2]=='1' || s[i-2]=='2')
                    dp[i] = dp[i-2];
                else 
                    return 0;
            }
            else if(s[i-2]=='1'||s[i-2]=='2' && s[i-1]>='1'&& s[i-1]<='6') {
                dp[i] = dp[i-1] +dp[i-2];//类似爬楼梯
            }
            else
                dp[i] = dp[i-1];
     
        }
        return dp[sz];
    }
};