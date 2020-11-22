class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                res.append("%20");
            else
                res.append(1,s[i]);
        }
        return res;

    }
};