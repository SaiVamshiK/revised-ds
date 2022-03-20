
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n,0));
        int elem=1;
        int left=0,right=n-1;
        int top=0,down=n-1;
        int dir=0;
        while((left<=right)&&(top<=down))
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    a[top][i]=elem++;
                }
                top++;
            }else if(dir==1)
            {
                for(int i=top;i<=down;i++)
                {
                    a[i][right]=elem++;
                }
                right--;
            }else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    a[down][i]=elem++;
                }
                down--;
            }else{
                for(int i=down;i>=top;i--)
                {
                    a[i][left]=elem++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return a;
    }
};
