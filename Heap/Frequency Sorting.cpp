
Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

Explanation:
Testcase1: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are same then smaller 
element comes first. So 4 4 comes first then comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
class Compare{
    public:
    bool operator()(pi a,pi b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};
// < => Max Heap
// > => Min Heap
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    unordered_map<int,int> mp;
	    int a;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a;
	        mp[a]++;
	    }
	    priority_queue<pi,vector<pi>,Compare> pq;
	    for(auto it=mp.begin();it!=mp.end();it++)
	    {
	        pq.push({it->second,it->first});
	    }
	    while(!pq.empty())
	    {
	        int val=pq.top().second;
	        int freq=pq.top().first;
	        while(freq--)
	        {
	            cout<<val<<' ';
	        }
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}



