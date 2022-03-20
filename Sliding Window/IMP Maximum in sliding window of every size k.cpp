//
//Given an array of integers A. There is a sliding window of size B which
//is moving from the very left of the array to the very right.
//You can only see the w numbers in the window. Each time the sliding window moves
//rightwards by one position. You have to find the maximum for each window.
//The following example will give you more clarity.
//
//The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

vector<int> Solution::slidingMaximum(const vector<int> &vec, int k) {
    int n=vec.size();
    int i=0,j=0;
    deque<int> q;
    vector<int> ans;
    while(j<n)
    {
        if((j-i+1)<k)
        {
            if(q.empty())
            {
                q.push_back(vec[j]);
            }else{
                while((!q.empty())&&(q.back()<vec[j]))
                {
                    q.pop_back();
                }
                q.push_back(vec[j]);
            }
            j++;
        }else if((j-i+1)==k)
        {
            if(q.empty())
            {
                q.push_back(vec[j]);
            }else{
                while((!q.empty())&&(q.back()<vec[j]))
                {
                    q.pop_back();
                }
                q.push_back(vec[j]);
            }
            ans.push_back(q.front());
            if(vec[i]==(q.front()))
            {
                q.pop_front();
            }
            i++;j++;
        }
    }
    return ans;
}

