class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<1) return 0;
        priority_queue<long, vector<long>, greater<long>> min_heap;

        min_heap.push(1);
        set<long> seen;
        seen.insert(1);
        vector<int> factors{2,3,5};
        long curUgly =1;
        long newUgly;
        for(int i=0;i<n;i++){
            curUgly = min_heap.top();
            min_heap.pop();
            for(auto &f:factors){
                newUgly = curUgly*f;
                if(seen.count(newUgly)==0){
                    min_heap.push(newUgly);
                    seen.insert(newUgly);
                }
            }

        }
        return (int)curUgly;
    }
};