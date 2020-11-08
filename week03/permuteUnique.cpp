class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> result;
        help(nums,0,result);
        return result;

    }
    void help(vector<int>nums, int pos, vector<vector<int>>& res){
        if(nums.size()==0) return;
        if(pos==nums.size()-1){
            res.push_back(nums);
            return;
        }

        for(int i=pos;i<nums.size();i++){
            if(pos!=i&&nums[pos]==nums[i]) continue;
            swap(nums[pos],nums[i]);
            help(nums,pos+1,res);
            swap(nums[pos],nums[i]);
        }
    }
};