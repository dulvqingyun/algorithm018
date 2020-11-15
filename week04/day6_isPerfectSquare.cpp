class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<=0) return false;
        if(num==1) return true;
        int low =1;
        int high = num;
        while(low<high){
                low++;
                high=num/low;
                if(low==high&&low*high==num)
                    return true;
        }
        return false;

    }
};