
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
 
*************************	SLIDING WINDOW NOT APPLICABLE HERE		*************************

vector<int> Solution::lszero(vector<int> &a) {
    int n=a.size();
    unordered_map<int,int> mp;
    int cur_sum=0;
    int startAns=-1,endAns=-1,maxLen=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cur_sum+=a[i];
        if(cur_sum==0)
        {
            int start=0,end=i;
            int len=end-start+1;
            if(maxLen<len)
            {
                maxLen=len;
                startAns=start;
                endAns=end;
            }
            if(mp.find(0)==mp.end())
            {
                mp.insert({cur_sum,i});
            }
            continue;
        }
        if(mp.find(cur_sum)!=mp.end())
        {
            int start=mp[cur_sum]+1,end=i;
            int len=end-start+1;
            if(maxLen<len)
            {
                maxLen=len;
                startAns=start;
                endAns=end;
            }
        }else{
            mp.insert({cur_sum,i});
        }
    }
    vector<int> ans;
    if(startAns==-1){
        return ans;
    }
    for(int i=startAns;i<=endAns;i++)
    {
        ans.push_back(a[i]);
    }
    return ans;
}

