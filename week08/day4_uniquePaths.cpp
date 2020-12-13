static int cache[101][101]={0};
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <=0 || n <= 0)
            return 0;
        if(m==1&&n==1) return 1;      
        else {
            if(cache[m-1][n]==0)
                cache[m-1][n] = uniquePaths(m-1,n);
            if(cache[m][n-1]==0)
                cache[m][n-1]=uniquePaths(m,n-1);
            return  cache[m-1][n] + cache[m][n-1];
        }
    }

};