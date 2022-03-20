
Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.

Example Input
Input 1:

 A = [5, 10, 3, 2, 50, 80]
 B = 78
Input 2:

 A = [-10, 20]
 B = 30


Example Output
Output 1:

 1
Output 2:

 1


int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    for(int i=0;i<(A.size());i++)
    {
        mp[A[i]]++;
    }
    for(int i=0;i<(A.size());i++)
    {
        mp[A[i]]--;
        int cur=A[i];
        cur=cur+B;
        if(mp.find(cur)!=mp.end()&&(mp[cur]>0))
        {
            return true;
        }
        mp[A[i]]++;
    }
    return false;
}


