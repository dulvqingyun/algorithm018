/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int head=0;
       return  help(preorder,head,inorder);
        
    }
    TreeNode* help(vector<int>&preorder, int& head, vector<int>& inorder){
        if(inorder.size()==0) return NULL;

        int split =-1;
        for(int i=0;i<inorder.size();i++){
            if(preorder[head]==inorder[i]){
                split=i;
                break;
            }
        }
        if(split==-1) return NULL;

        TreeNode* newHead = new TreeNode(inorder[split]);

        vector<int> left_inorder;
        for(int i=0;i<split;i++) 
            left_inorder.push_back(inorder[i]);

        vector<int> right_inorder;
        for(int j=split+1;j<inorder.size();j++)
            right_inorder.push_back(inorder[j]);

        if(left_inorder.size()!=0){
            head++;
            newHead->left = help(preorder,head,left_inorder);
        }
        if(right_inorder.size()!=0){
            head++;
            newHead->right = help(preorder,head,right_inorder);
        }

        return newHead;        
    }
};