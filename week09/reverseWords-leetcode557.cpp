class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i =0;
        while(i< n){
            if(s[i]!=' '){
                int begin = i;
                while(i<n && s[i]!=' ') {i++;}
                int end =i-1;
                while(begin<end) swap(s[begin++],s[end--]);
            }
            else{
                i++;
            }
        }
        return s;
    }
};