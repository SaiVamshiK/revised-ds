
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int n=a.size(),m=a[0].size();
        int r=0,c=m-1;
        while(c>=0&&(r<n))
        {
            int val=a[r][c];
            if(x==val)
            {
                return true;
            }else if(x<val)
            {
                c--;
            }else{
                r++;
            }
        }
        return false;
    }
};
