Given a string you need to print the size of the longest possible substring that has exactly k unique characters. If there is no possible substring print -1.
Example
For the string aabacbebebe and k = 3 the substring will be cbebebe with length 7.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    int k;
	    cin>>s;
	    cin>>k;
	    int n=s.size();
	    int ans=INT_MIN;
	    int i=0,j=0;
	    unordered_map<char,int> mp;
	    while(j<n)
	    {
	        mp[s[j]]++;
	        if(mp.size()<k)
	        {
	            j++;
	        }else if(mp.size()==k)
	        {
	            ans=max(ans,j-i+1);
	            j++;
	        }else{
	            while(mp.size()>k)
	            {
	                char cur_ch=s[i];
	                auto itr=mp.find(cur_ch);
	                int cur_ch_freq=itr->second;
	                mp.erase(itr);
	                cur_ch_freq--;
	                if(cur_ch_freq!=0)
	                {
	                    mp.insert({cur_ch,cur_ch_freq});
	                }
	                i++;
	            }
	            if(mp.size()==k)
	            {
	                ans=max(ans,j-i+1);
	            }
	            j++;
	        }
	    }
	    if(ans==INT_MIN)
	    {
	        cout<<-1<<endl;
	    }else{
	        cout<<ans<<endl;
	    }
	}
	return 0;
}












