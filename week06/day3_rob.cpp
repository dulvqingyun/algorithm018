class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        return max( help(nums,0, sz-2), help(nums,1,sz-1));
    }
    int help(vector<int>nums, int start, int end){
        int sz = end-start+1;
        vector<int> dp(sz,0);
        dp[0] = nums[start];
        for(int i =1;i<sz;i++){
            if (i == 1) 
                dp[i] = max(nums[start], nums[start+1]);
            else
                dp[i]= max(dp[i-1], dp[i-2]+nums[start+i]);
        }
        return dp[sz-1];
    }
};