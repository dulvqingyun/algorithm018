class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        unordered_map<int,int>income;
        // income[0]=INT_MAX;
        for (int i=0;i<bills.size();i++){
            income[bills[i]]++;
            int num = bills[i]-5;
            if(num==15){
                if(income[10]>0&&income[5]>0){
                    income[10]--;
                    income[5]--;
                }
                else if(income[5]>2)
                    income[5] -= 3;
                else
                    return false;

            }
            else if(num==5){
                if(income[5]>0)
                    income[5]--;
                else
                    return false;
            }        
        }
        return true;
    }
};