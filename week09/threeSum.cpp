class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
    auto sz = nums.size();
    if(sz<3) return {};

    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int i =0;
    while(i<sz-2 && nums[i]<=0){

        int a = nums[i];
        int j = i+1;
        int k = sz-1;
        while(j<k){
            int b = nums[j];
            int c = nums[k];
            int sum = a+b+c;
            if(sum==0) ret.push_back({nums[i], nums[j], nums[k]});
            if(sum<=0){
                while(j<k && nums[j]==b) j++;
            }
            if(sum>=0){
                while(j<k && nums[k]==c) k--;
            }
        }
        while(i<sz-2 && nums[i]==a) i++;
    }
    return ret;
    }
};