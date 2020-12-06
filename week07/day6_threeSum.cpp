class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
    auto sz = nums.size();
    if(sz<3) return {};

    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int i =0;
    while(i<sz-2 && nums[i]<=0){

        auto a = nums[i];

        int left = i+1;
        int right = sz-1;
        while(left<right){
            auto b = nums[left];
            auto c = nums[right];
            int sum = a+b+c;
            if(sum==0) ret.push_back({a,b,c});
            if(sum<=0){
                while(left<right&&nums[left]==b) left++;
            }
            if(sum>=0){
                while(right>left&& nums[right]==c) right--;
            }
        }
        while( i<sz-2&&nums[i]==a) i++;

    }

    return ret;
    
    }
};