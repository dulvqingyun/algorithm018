class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(len<2) return 0;
        int res = 0;
        stack<int> st;
        st.push(-1);//第一个无效的括号，初始化为-1
        for(int i =0; i< len; i++){
            if(s[i]=='(')   st.push(i);
            else{
                 st.pop();
                if(st.empty())  st.push(i);
                else res = max(res, i-st.top());  
            }   
        }
        return res;
    }
};