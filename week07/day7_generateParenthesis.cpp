class Solution {
public:
    vector<string> generateParenthesis(int n) {
        help("",n,n);
        return  ret;
    }
    
    void help(string str, int left, int right){
        if(left<0||right<0)
            return;

        if (right==0) ret.push_back(str);

        help(str+"(", left-1, right);
        if(left<right)
            help(str+")",left,right-1);


    }

private:
    vector<string> ret;

};