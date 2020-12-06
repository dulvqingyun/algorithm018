class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ret = nums[0];
        int dp =nums[0];
        for(int i =1;i<n;i++){
            dp = max(nums[i],dp+nums[i]);
            ret = max(dp,ret);
        }
        return ret;
    }
};