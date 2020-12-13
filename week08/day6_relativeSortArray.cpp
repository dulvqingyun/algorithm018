class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    
    vector<int> result;
    int freq[1001]={0};
    for(auto& i : arr1) freq[i]++;
    for(auto& j : arr2){
        while(freq[j]){
            result.push_back(j);
            freq[j]--;
        }
    }

    for(int k =0; k<1001; k++){
        while(freq[k]!=0){
            result.push_back(k);
            freq[k]--;
        }
    }
    return result;     

    }
};