class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<int> dp(n,res);
        // for(int i =0;i<n;i++)
        //     dp[i]=i;
        for (int j = 1;j < n;j++){
            dp[j]= max(nums[j],nums[j]+dp[j-1]);
            res = max(res,dp[j]);
        }
        return  res;
    }
};