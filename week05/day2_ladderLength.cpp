class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
                unordered_set<string>wordSet{wordList.begin(), wordList.end()};
        if(wordSet.find(endWord)==wordSet.end()) return 0;

        unordered_map<string, int> visitMap;

        queue<string> qu;
        qu.push(beginWord);
        visitMap.insert({beginWord,1});
        while(!qu.empty()){
            string curWord = qu.front();
            qu.pop();
            int path = visitMap[curWord];
            for(int i =0;i<curWord.size();i++){
                string newWord = curWord;
                for(int j=0;j<26;j++){
                    newWord[i] = 'a'+j;
                    if(newWord==endWord){return path+1;}
                    else if (wordSet.find(newWord)!=wordSet.end() &&
                        visitMap.find(newWord)==visitMap.end()){
                            visitMap.insert({newWord,path+1});
                            qu.push(newWord);
                        }
                }
            }
        }
        return 0;
        
    }
};