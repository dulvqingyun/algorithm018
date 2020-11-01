class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        _preorder(root,result);
        return result;
    }
    void _preorder(Node* root, vector<int>& result)
    {
        if(!root) return ;
        result.push_back(root->val);
        for(int i =0;i<root->children.size();i++){
            _preorder(root->children[i],result);
        }
        return; 

    }

};