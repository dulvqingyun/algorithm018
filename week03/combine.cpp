class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        help(n,1,k,temp);
        return res;
    }

private:
    vector<vector<int>> res;
    void help(int n, int pos, int k, vector<int> temp){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }     
        for(int i=pos;i<=n;i++){
            temp.push_back(i);
            help(n,i+1,k,temp);  
            temp.pop_back();
        }
    }
        
};