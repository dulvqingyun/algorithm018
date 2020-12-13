class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> wordSet(bank.begin(), bank.end());
        if(wordSet.find(end)==wordSet.end()) return -1;

        char choices[4]={'A','C','G','T'};
        unordered_map<string, int> visitMap;
        queue<string> qu;
        qu.push(start);
        visitMap.insert({start,0});
        while(!qu.empty()){
            string cur = qu.front();
            qu.pop();
            int path = visitMap[cur];
            for(int i=0;i<cur.size();i++){
                 string newWord = cur;
                 for(int j=0;j<4;j++){
                     newWord[i] = choices[j]; //依次替换cur中第i个单词
                     if(newWord==end)
                        return path+1;
                    if(wordSet.find(newWord)!=wordSet.end() && 
                        visitMap.find(newWord)==visitMap.end()){//字典中有新单词
                        qu.push(newWord);
                        visitMap.insert({newWord,path+1});
                    }
                 }
            }
        }
        return -1;      


    }
};