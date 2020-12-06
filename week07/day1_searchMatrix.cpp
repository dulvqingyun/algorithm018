class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        int L = 0;
        int R = m*n-1;
        while(L<=R){
            int mid = L+(R-L)/2;
            if(target==matrix[mid/n][mid%n]) return true;
            else if(target>matrix[mid/n][mid%n]) L = mid+1;
            else if(target<matrix[mid/n][mid%n]) R = mid-1;
        }
        return false;
    }
};