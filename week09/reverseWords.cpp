class Solution {
public:
    string reverseWords(string s) { 
        stringstream ss(s);
        stack<string> st;
        string temp;
        while(ss>>temp){
            st.push(temp);
            st.push(" ");
        }
        if(!st.empty()) st.pop();//弹出最后入栈的空格
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};