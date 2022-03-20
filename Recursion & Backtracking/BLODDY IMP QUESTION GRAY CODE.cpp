
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

vector<int> func(int n)
{
    if(n==1)
    {
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        return arr;
    }
    vector<int> temp=func(n-1);
    vector<int> ans;
    for(int i=0;i<(temp.size());i++)
    {
        ans.push_back(temp[i]);
    }
    for(int i=(temp.size()-1);i>=0;i--)
    {
        int cur=temp[i];
        int x=(1<<(n-1))+(cur);
        ans.push_back(x);
    }
    return ans;
}
vector<int> Solution::grayCode(int A) {
    return func(A);
}

