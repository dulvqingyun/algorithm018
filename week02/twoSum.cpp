    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz<2) return {};
        unordered_map<int,int>table;
        for(int i=0;i<sz;i++){
            if(table.count(nums[i]))
                return {i,table[nums[i]]};
            else{
                table[target-nums[i]] =i;
            }
        }
        return {};

    }