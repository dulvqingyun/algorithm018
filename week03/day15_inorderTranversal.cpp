class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        stack<TreeNode*>st;
        TreeNode* temp = root;
        while(!st.empty()||temp){
            if(!temp){
                st.push(temp);
                temp = temp->left;
            }
            else{
                temp = st.top();
                st.pop();
                res.push_back(temp->val);
                temp = temp->right;
            }
        }
        return res;   
    }
};