class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size()==0) return {};
        permuteUnique_(nums,0);
        return result;
    }

    void permuteUnique_(vector<int>& nums, int pos){
        if(pos==nums.size()-1){
            result.push_back(nums);
            return ;
        }
        unordered_set<int> seen;
        for(int i =pos; i< nums.size(); i++){
            if(!seen.count(nums[i])){
                swap(nums[pos],nums[i]);
                permuteUnique_(nums,pos+1);
                swap(nums[pos],nums[i]);
                seen.insert(nums[i]);
            }

        }
    }

    
private:
    vector<vector<int>> result;
};