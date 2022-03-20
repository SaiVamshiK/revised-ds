
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int n=a.size(),m=a[0].size();
        int r=0,c=m-1;
        while(r<n)
        {
            if(x==a[r][c])
            {
                return true;
            }
            else if(x<a[r][c])
            {
                break;
            }else{
                r++;
            }
        }
        if(r==n)
        {
            return false;
        }
        return binary_search(a[r].begin(),a[r].end(),x);
    }
};
