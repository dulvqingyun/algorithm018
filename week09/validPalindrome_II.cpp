class Solution {
public:
    bool validPalindrome(string s) {
        int start =0;
        int end = s.size()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return check(s,start,end-1)||check(s,start+1,end);
            }
            start++;
            end--;
        }
        return true;
    }
    bool check(string s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])
             return false;
        }
        return true;
    }
};