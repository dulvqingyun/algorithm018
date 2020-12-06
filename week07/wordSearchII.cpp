class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size()==0) return {};
        int m = board.size();
        if(m==0) return {};
        int n = board[0].size();

        for( auto& word:words){
            insert(word,root);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string first;
                first.insert(0,1,board[i][j]);
                dfs(board,i,j,root);
            }
        }

        return result;

    }

public:
    struct node{
        bool isEnd{false};
        unordered_map<char,node*> child;
        string word ="";
    };

    void insert(string word, node* root) {
        node* temp  = root;
        for(auto ch:word){
            if(!temp->child.count(ch)){
                temp->child[ch] = new node();       
            }
            temp = temp->child[ch];
        }
        temp->isEnd = true;
        temp->word = word;

    }


private:
    node* root = new node();
    // int dx[4]={0,1,0,-1};
    // int dy[4]={-1,0,1,0};
    vector<string> result;
public:
   bool dfs(vector<vector<char>>& board,int x, int y, node* root){
        if(x<0 || x>=board.size() || y<0 || y>=board[x].size() || board[x][y]=='@'||!root)
            return false;
          
        char temp = board[x][y];
        board[x][y]='@';
        string newStr;
        newStr.insert(0,1,temp);
        root = root->child[temp];
        if(root){
            if(root->word != ""){
                result.push_back(root->word);
                root->word = "";
            }
                
            if(dfs(board,x,y+1,root)) return true;
            if(dfs(board,x+1,y,root)) return true;
            if(dfs(board,x,y-1,root)) return true;
            if(dfs(board,x-1,y,root)) return true;  
        }
      
        board[x][y] = temp;
        return false;
    }

};