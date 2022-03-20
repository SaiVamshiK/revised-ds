Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.


vector <int> countDistinct (int a[], int n, int k)
{
    int i=0,j=0;
    unordered_map<int,int> mp;
    vector <int> ans;
    while(j<n)
    {
        mp[a[j]]++;
        if((j-i+1)<k)
        {
            j++;
        }else if((j-i+1)==k)
        {
            ans.push_back(mp.size());
            int cur=a[i];
            auto it=mp.find(cur);
            int cur_freq=it->second;
            cur_freq--;
            mp.erase(it);
            if(cur_freq!=0)
            {
                mp.insert({cur,cur_freq});
            }
            i++;
            j++;
        }
    }
    return ans;
}
