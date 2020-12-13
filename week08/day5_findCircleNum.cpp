class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if(N==0) return 0;
        unordered_set<int>visited;
        int count =0;
        for(int i =0; i< N; i++){
            if(0==visited.count(i)){
                dfs(M,i, visited);
                count++;
            }         
        }
        return count;
    }
    void dfs(vector<vector<int>>& M, int i, unordered_set<int>& visited){
        for(int j =0; j<M.size(); j++){
                if(M[i][j]==1 && 0==visited.count(j)){
                    visited.insert(j);
                    dfs(M,j,visited);
                }   
        }
    }

};