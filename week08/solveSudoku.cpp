class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        int m = board.size();
        if(m==0) return ;
        int n = board[0].size();
        init_board(board);
        _solveSudoku(board,0,row_set,col_set,block_set);       
    }

private:
    bool _solveSudoku(vector<vector<char>>& board, int step, unordered_set<char> row_set[9],
        unordered_set <char> col_set[9], unordered_set<char> block_set[9]){
        if (step>80) return true;
        int i = step/9;
        int j = step%9;    
        if(board[i][j]=='.'){
            for(char k ='1'; k<='9'; k++){
                if(row_set[i].count(k)||col_set[j].count(k)||block_set[i/3*3+j/3].count(k))
                    continue;
                else{
                    board[i][j]=k;
                    row_set[i].insert(k);
                    col_set[j].insert(k);
                    block_set[i/3*3+j/3].insert(k);
                    if(_solveSudoku(board,step+1,row_set,col_set,block_set)) return true;
                    
                    row_set[i].erase(k);
                    col_set[j].erase(k);
                    block_set[i/3*3+j/3].erase(k);
                }
                board[i][j]='.';
            }
        }
        else{
            return _solveSudoku(board,step+1,row_set,col_set,block_set);
        }
        return false;
        
    }
    
    void init_board(vector<vector<char>>& board){
        int m = board.size();
        if(m==0) return ;
        int n = board[0].size();
        for(int i =0; i<m; i++){
            for (int j=0; j<n; j++){
                if(board[i][j]!='.'){
                    row_set[i].insert(board[i][j]);
                    col_set[j].insert(board[i][j]);
                    block_set[i/3*3+j/3].insert(board[i][j]);
                }
            }
        }
    }
private:
    unordered_set<char> row_set[9];
    unordered_set<char> col_set[9];
    unordered_set<char> block_set[9];
};