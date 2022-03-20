
// Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int *a=new int[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;
	    cin>>k;
	    int i=0,j=0;
	    queue<int> q;
	    while(j<n)
	    {
	        if((j-i+1)<k)
	        {
	            if(a[j]<0)
	            {
	                q.push(a[j]);
	            }
	            j++;
	        }else if((j-i+1)==k)
	        {
	            if(a[j]<0)
	            {
	                q.push(a[j]);
	            }
	            if(!q.empty())
	            {
	                cout<<(q.front())<<' ';
    	            if((q.front())==a[i])
    	            {
    	                q.pop();
    	            }
	            }else{
	                cout<<0<<' ';
	            }
	            i++;
	            j++;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}










