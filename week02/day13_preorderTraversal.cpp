class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        _preorderTraversal(root,result);
        return result;
        
    }
    void _preorderTraversal(TreeNode* root, vector<int>& reuslt){
        if(!root) return;
        TreeNode* temp = root;
        stack<TreeNode*> st;
        while(!st.empty()||temp){
            if(temp){
                reuslt.push_back(temp->val);
                st.push(temp);
                temp = temp->left;
            }
            else{
                temp= st.top();
                st.pop();
                temp = temp->right;
            }
        }
    }
};