class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>table;
        for(auto num:nums)
            table[num]++;
        
        priority_queue<pair<int,int>> que;
        for(auto m:table)
            que.push(make_pair(m.second,m.first));

        vector<int> vec;
        for(int i=0;i<k;i++){
            vec.push_back(que.top().second);
            que.pop();
        } 

        return vec;

    }
};