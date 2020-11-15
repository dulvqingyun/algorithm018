/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord)==wordSet.end()) return 0;

        unordered_map<string, int> visitMap;
        queue<string> qu;
        qu.push(beginWord);
        visitMap.insert({beginWord,1});
        while(!qu.empty()){
            string cur = qu.front();
            qu.pop();
            int path = visitMap[cur];
            for(int i=0;i<cur.size();i++){
                 string newWord = cur;
                 for(int j=0;j<26;j++){
                     newWord[i] = j + 'a'; //依次替换cur中第i个单词
                     if(newWord==endWord)
                        return path+1;
                    if(wordSet.find(newWord)!=wordSet.end() && 
                        visitMap.find(newWord)==visitMap.end()){//字典中有新单词
                        qu.push(newWord);
                        visitMap.insert({newWord,path+1});
                    }
                 }
            }
        }
        return 0;        
    }

};
// @lc code=end

