Problem Statement
You are given three rods (numbered 1 to 3), and ‘N’ disks initially placed on the first rod, one on top of each other in increasing order of size ( the largest disk is at the bottom). You are supposed to move the ‘N’ disks to another rod(either rod 2 or rod 3) using the following rules and in less than 2 ^ (N) moves.
1. You can only move one disk in one move. 
2. You can not place a larger disk on top of a smaller disk.
3. You can only move the disk at the top of any rod.    

void toh(int n,int src,int dest,int helper,vector<vector<int>> &ans)
{
    if(n==1)
    {
        ans.push_back({src,dest});
        return ;
    }
    toh(n-1,src,helper,dest,ans);
    ans.push_back({src,dest});
    toh(n-1,helper,dest,src,ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;
    toh(n,1,3,2,ans);
    return ans;
}
