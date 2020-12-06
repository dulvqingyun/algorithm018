vector<vector<int>> levelOrder(TreeNode* root) { 
        if(!root) return {};
        vector<vector<int>> ret;
        vector<int> tem_ret;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            auto sz = que.size();          
            for(int i = 0; i < sz; i++){
                TreeNode* temp = que.front();  
                tem_ret.push_back(temp->val);    
                que.pop();   
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
                
            }
            ret.push_back(tem_ret);
            tem_ret.clear();
        }
        return ret;
    }