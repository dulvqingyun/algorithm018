class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(target==matrix[mid/n][mid%n])
                return true;
            else if (target>matrix[mid/n][mid%n])
                left=mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};