class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return{};
        permute_(nums,0);
        return answer;

    }
private:
    vector<vector<int>>answer;
    void permute_(vector<int>& nums, int pos){
        if(pos>=nums.size()-1){
            answer.push_back(nums);
            return ;
        }
        for(int i = pos; i<nums.size(); i++ ){
            swap(nums[i],nums[pos]);
            permute_(nums,pos+1);
            swap(nums[i], nums[pos]);
        }
    }
};