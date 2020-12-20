class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>neddle;
        vector<int> res;
        unordered_map<char,int>window;
        for(auto& ch:p)
            neddle[ch]++;
        
        int left(0),right(0);
        int match=0;
        while(right<s.size()){
            char chR = s[right];
            if (neddle.count(chR)){
                window[chR]++;
                if(neddle[chR]==window[chR])
                    match++;            
            }
            while(match==neddle.size()){
                if(right-left+1==p.size())
                    res.push_back(left);
                char chL = s[left];
                if(neddle.count(chL)){
                    if(neddle[chL]==window[chL])
                        match--;
                    window[chL]--;
                }      
                left++;   
            }
            right++;
        }
        return res;
    }
};