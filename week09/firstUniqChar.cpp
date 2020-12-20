class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> table;
        for( auto & ch: s){
            table[ch]++;
        }
        for( auto & ch:s){
            if(table[ch]==1) return ch;
        }
        return ' ';

    }
};