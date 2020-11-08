class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        help(nums,0,result);
        return result;

    }
    void help(vector<int>nums, int pos, vector<vector<int>>& res){
        if(nums.size()==0) return ;
        if(pos>=nums.size()-1){
            res.push_back(nums);
            return ;
        }
         
        for(int i=pos;i<nums.size();i++){
            // res.push_back(nums[i]);
            std::swap(nums[pos],nums[i]);
            help(nums,pos+1,res);
            // res.pop_back();
            std::swap(nums[pos],nums[i]);
        }
    }

};