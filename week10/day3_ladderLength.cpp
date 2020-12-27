class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset;
        for(auto& str: wordList) wordset.insert(str);
        if(!wordset.count(endWord)) return 0;
        unordered_set<string> visited;
        queue<string>qu;
        int count=0;
        qu.push(beginWord);
        count++;
        while(!qu.empty()){
            int sz = qu.size();
            for(int i =0; i<sz; i++){
                string cur = qu.front();
                qu.pop();
                for(int i = 0; i< cur.size();i++){
                    string temp = cur;
                    for( char ch = 'a'; ch<='z'; ch++){
                        temp[i]=ch;
                        if(wordset.count(temp) && !visited.count(temp))
                        {   if(temp==endWord)   return count+1;
                            qu.push(temp);
                            visited.insert(temp);
                        }
                    }
                }    
            }
            count++;
        }
        return 0;
    } 
};