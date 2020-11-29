class Solution {
public:
    vector<int> preorder(Node* root) {

        help(root);
        return res;
        
    }
private:
    vector<int> res;
    void help(Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(int i =0; i<root->children.size(); i++)
            help(root->children[i]);
    }
};