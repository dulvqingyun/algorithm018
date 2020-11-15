/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count =1;
        for (int i = 1;i< nums.size();i++){
            if(candidate==nums[i])
                count++;
            else
            {
                count--;
            }
            if(count==0){
                candidate=nums[i];
                count=1;
            }
            

        }
        return candidate;
        
        
    }
};
// @lc code=end

