vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int>table;
    for(int i=0;i<nums.size(); i++){
        if(table.count(nums[i]))
            return {table[num[i]],i};
        else{
            table.insert({target-nums[i],i});
        }
    }
    return {};
}