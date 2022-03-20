
Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

bool isOk(unordered_map<char,int> &mp)
{
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if((it->second)>1)
        {
            return false;
        }
    }
    return true;
}
int Solution::lengthOfLongestSubstring(string s) {
    int n=s.size();
    int a[26]={0};
    int i=0,j=0;
    int ans=INT_MIN;
    unordered_map<char,int> mp;
    while(j<n)
    {
        mp[s[j]]++;
        if(isOk(mp))
        {
            ans=max(ans,j-i+1);
            j++;
        }else{
            while(!isOk(mp))
            {
                mp[s[i]]--;
                i++;
            }
            j++;
        }
    }
    return ans;
}

