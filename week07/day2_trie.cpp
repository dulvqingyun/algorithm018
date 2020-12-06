class Trie {
public:
    struct node{
        bool isEnd{false};
        unordered_map<char, node*> child;

    };
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* temp = root;
        for(auto ch:word){
            if(!temp->child.count(ch)){
                temp->child[ch] = new node();       
            }
             temp = temp->child[ch];
        }
        temp->isEnd = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* temp = root;
        for( auto ch : word){
            if(!temp->child.count(ch)) return false;           
            temp = temp->child[ch];       
        }
        return temp->isEnd;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* temp = root;
        for( auto ch: prefix){
            if(!temp->child.count(ch)) return false;
            temp = temp->child[ch];          
        }
        return  true;
    }
private:
    node* root;
};