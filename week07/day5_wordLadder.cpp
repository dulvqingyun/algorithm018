class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for(auto& word:wordList) wordSet.insert(word);

        unordered_map<string,int> visited;
        queue<string> qu;
        qu.push(beginWord);
        visited[beginWord]=1;

        while(!qu.empty()){
            string curWord = qu.front();
            qu.pop();
            
            if(curWord==endWord){

                return visited[curWord];
            }

            for(int i=0;i<curWord.size();i++){
                char tempWord = curWord;
                for(int j=0; j< 26; j++){
                  tempWord[i]= 'a'+j;
                  if(wordSet.count(tempWord) && !visited.count(tempWord)){
                      qu.push(tempWord);
                      visited[tempWord] = visited[curWord]+1;
                  }

                }
            }
        }
        return  0;

};