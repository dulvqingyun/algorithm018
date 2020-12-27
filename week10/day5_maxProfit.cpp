class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        int answer =0;
        for( int i =0; i< n-1; i++){
            if(prices[i]<prices[i+1]) 
                answer+=(prices[i+1]-prices[i]);
        }
        return answer;
    }
};