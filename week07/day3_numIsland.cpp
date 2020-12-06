class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

//递归
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }


    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }


    int getCount() const {
        return count;
    }


private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind union_find(grid);
        for(int i =0; i< m; i++){
            for (int j =0; j < n; j++){
                if(grid[i][j]== '1')
                {
                    if(j+1<n && grid[i][j+1]=='1' )   union_find.unite(i*n+j,i*n+j+1);
                    if(j-1>=0 && grid[i][j-1]=='1')  union_find.unite(i*n+j,i*n+j-1);
                    if(i+1<m && grid[i+1][j]=='1')   union_find.unite(i*n+j,(i+1)*n+j);
                    if(i-1>=0 && grid[i-1][j]=='1')   union_find.unite(i*n+j, (i-1)*n+j);    
                }
                    
            }
        }
        return union_find.getCount();
    }


};