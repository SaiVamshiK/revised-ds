
Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, and a number X is given. 
The task is to find whether element X is present in the matrix or not.


Example 1:

Input:
N = 3, M = 3
mat[][] = 3 30 38 
         44 52 54 
         57 60 69
X = 62
Output:
0 
Explanation:
62 is not present in the
matrix, so output is 0

ALGO:
	We start at a point and check if it is the key then we would return true
	otherwise we would be eliminating one row or one column and continue the process until we find the key

int matSearch (int n, int m, int a[][m], int x)
{
    int i=0,j=m-1;
    while(i>=0&&(j>=0)&&(i<n)&&(j<m))
    {
        if(a[i][j]==x)
        {
            return 1;
        }
        if(x>a[i][j])
        {
            // down
            i++;
        }else{
            // left
            j--;
        }
    }
    return 0;
}

