class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphic_(s,t) && isIsomorphic_(t,s);
        
    }
    bool isIsomorphic_(string s, string t){
        unordered_map<char,char> table_s;
        unordered_map<char, char> table_t;
        for(int i =0; i<s.size(); i++){
            char ch_s = s[i];
            char ch_t = t[i];
            if(table_s.count(ch_s)){
                if(table_s[ch_s]!=ch_t) return false; 
            }
            else{
                table_s[ch_s] =ch_t;
            }
        }
        return true;
    }
    
};