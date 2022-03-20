
Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.


Input Format:

The first and the only argument of input will be an integer array A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
    => 0 : If you cannot reach the last index.
    => 1 : If you can reach the last index.

int Solution::canJump(vector<int> &a) {
    int n=a.size();
    bool temp[n];
    temp[n-1]=true;
    for(int i=n-2;i>=0;i--)
    {
        int move=a[i];
        if(move==0)
        {
            temp[i]=false;
            continue ;
        }
        bool done=false;
        for(int j=i+1;move>0&&(j<n);j++,move--)
        {
            if(temp[j])
            {
                done=true;
                break;
            }
        }
        temp[i]=done;
    }
    return temp[0];
}

