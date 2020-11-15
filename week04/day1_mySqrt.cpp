class Solution {
public:
    int mySqrt(int x) {
        if(x<0) return -1;
        if(x==1) return 1;

        int left =0;
        int right = x;
        long mid=0;
        while(left<right){
            mid = left+(right-left)/2;
            if(mid==left||mid==right) break;
            if (mid*mid == x)
                break ;
            else if(mid*mid > x)
                right=mid;
            else
                left=mid;

        }
        return mid;
    }
};