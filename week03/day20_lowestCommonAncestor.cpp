class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==q||root==p) return root;

        TreeNode* nodeL = lowestCommonAncestor(root->left,p,q);
        TreeNode* nodeR = lowestCommonAncestor(root->right,p,q);

        if(nodeL&&nodeR) return root;
        if(nodeL) return nodeL;
        if(nodeR) return nodeR;
        return NULL;  
    }
};