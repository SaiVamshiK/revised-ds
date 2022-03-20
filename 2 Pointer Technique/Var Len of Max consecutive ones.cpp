You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

Seen this question i

******************************** SEE THIS SOLUTION ********************************

vector<int> Solution::maxone(vector<int> &a, int k) {
    int n=a.size();
    int i=0,j=0;
    int max_len=0;
    int start,end;
    while(j<n)
    {
        if(a[j]==0)
        {
            k--;
        }
        if(k>0)
        {
            if(max_len<(j-i+1))
            {
                start=i;
                end=j;
                max_len=j-i+1;
            }
            j++;
        }else if(k==0)
        {
            if(max_len<(j-i+1))
            {
                start=i;
                end=j;
                max_len=j-i+1;
            }
            j++;
        }else{
            while(k<0)
            {
                if(a[i]==0)
                {
                    k++;
                }
                i++;
            }
            j++;
        }
    }
    vector<int> ans;
    for(int i=start;i<=end;i++)
    {
        ans.push_back(i);
    }
    return ans;
}



vector<int> Solution::maxone(vector<int> &a, int k) {
    int n=a.size();
    int i=0,j=0;
    pair<int,int> ans;
    int len=INT_MIN;
    while(j<n)
    {
        if(a[j]==0)
        {
            k--;
        }
        if(k>0)
        {
            int cur_len=j-i+1;
            if(len<cur_len)
            {
                len=cur_len;
                ans.first=i;
                ans.second=j;
            }
            j++;
        }else if(k==0)
        {
            j++;
            while(j<n&&(a[j]==1))
            {
                j++;
            }
            j--;
            int cur_len=j-i+1;
            if(len<cur_len)
            {
                len=cur_len;
                ans.first=i;
                ans.second=j;
            }
            j++;
        }else{
            while(k<0)
            {
                if(a[i]==0)
                {
                    k++;
                }
                i++;
            }
            j++;
        }
    }
    vector<int> fin;
    for(int start=ans.first;start<=ans.second;start++)
    {
        fin.push_back(start);
    }
    return fin;
}

