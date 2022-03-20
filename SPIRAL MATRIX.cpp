Given an m x n matrix, return all elements of the matrix in spiral order

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int left=0,right=m-1;
        int top=0,down=n-1;
        int dir=0;
        vector<int> ans;
        while(left<=right&&(top<=down))
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(a[top][i]);
                }
                top++;
            }else if(dir==1)
            {
                for(int i=top;i<=down;i++)
                {
                    ans.push_back(a[i][right]);
                }
                right--;
            }else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(a[down][i]);
                }
                down--;
            }else{
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(a[i][left]);
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};
