    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size()||!nums2.size()) return {};
        vector<int>output;
        unordered_map<int,int> table;
        for(int i=0;i<nums1.size();i++){
            table[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();j++){
            if(table[nums2[j]]>0){
                table[nums2[j]]--;
                output.push_back(nums2[j]);
            }
        }

        return output;

    }