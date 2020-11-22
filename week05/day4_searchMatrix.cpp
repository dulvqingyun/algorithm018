class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
		int row=0;
		int col = n-1;
		while(row<m&&col>=0){
			if(matrix[row][col]==target)
				return true;
			else if(matrix[row][col]>target)
				col--;
			else
				row++;
		}

        return false;
    }
};