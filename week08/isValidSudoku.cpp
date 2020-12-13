class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> block[9];

        for(int i =0; i<board.size(); i++){
            for (int j =0; j < board[i].size(); j++){
               if(board[i][j]!='.'){
                   char num = board[i][j];
                   if(row[i].count(num) || col[j].count(num) || block[(i/3)*3+j/3].count(num))
                        return false;
                    else{
                        row[i].insert(num);
                        col[j].insert(num);
                        block[(i/3)*3+j/3].insert(num);
                    }
               } 

            }
        }

        return true;

    }
};