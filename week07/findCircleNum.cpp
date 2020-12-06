class UnionFind {
public:
    UnionFind(int N):count(N) {
       for(int i=0;i<N;i++){
           parent.push_back(i);
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
        int p_x = find(x);
        int p_y = find(y);
        if (p_x != p_y) {
         parent[p_x]=p_y;
         count--;
        }
    }

    int getCount() const {
        return count;
    }


private:
    vector<int> parent;
    // vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if(!N) return 0;
        UnionFind union_find(N);
        for(int i=0;i<M.size();i++){
            for(int j =i+1; j < M[i].size(); j++){
                if(M[i][j]==1)
                    union_find.unite(i,j);
            }
        }

        return union_find.getCount();
    }

};