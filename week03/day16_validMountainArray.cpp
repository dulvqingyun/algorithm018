class Solution {
public:
    bool validMountainArray(vector<int>& A) {

        int begin=0;
        int end = A.size()-1;
        while(begin<end &&A[begin+1]>A[begin])
             begin++;
        while(end>begin&&A[end]<A[end-1] )
             end--;
 
        return begin > 0 && end < A.size() - 1 && begin == end;

    }
};