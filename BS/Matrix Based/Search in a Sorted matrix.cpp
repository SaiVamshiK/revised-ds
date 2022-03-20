
You are given a 2-D matrix of dimensions NxM, each row of the matrix is sorted in non-decreasing order and the 
first element of each row is greater than or equal to the last element of the previous row. You are also given an 
integer ‘X’, you are supposed to find whether X is present in the given matrix or not.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases are as follows.

The first line of each test case contains three integers ‘X’,‘N’ and ‘M’ separated by a single space denoting the element 
to be searched, the number of rows in the matrix, and the number of columns in the matrix respectively.

The next ‘N’ lines contain ‘M’ integers each denoting the elements of the matrix.
Output Format :
For each test case, print “Yes”(without quotes) if ‘X’ is present in the matrix otherwise print “No”.

Print the output of each test case on a new line. 

Sample Input 1 :
2
4 2 2
2 4
8 12
7 3 4
1 2 4 5
8 12 14 16
23 25 26 29
Sample Output 1 :
Yes
No

bool findInMatrix(int x, vector<vector<int>> &a)
{
    int n=a.size(),m=a[0].size();
    int i=0,j=0;
    while((i>=0)&&(i<n)&&(j>=0)&&(j<m))
    {
        if(a[i][j]==x)
        {
        	return true;
        }
        int cur_row_max=a[i][m-1];
        if(x>cur_row_max)
        {
        	i++;
        }else{
            return binary_search(a[i].begin(),a[i].end(),x);
        }
    }
    return false;
}
