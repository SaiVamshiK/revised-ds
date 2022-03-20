
Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.
The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]

vector<int> Solution::slidingMaximum(const vector<int> &a, int k) {
    int n=a.size();
    vector<int> ans;
    deque<int> Q;
    int i=0,j=0;
    while(j<n)
    {
        while((!Q.empty())&&(Q.back()<a[j]))
        {
            Q.pop_back();
        } 
        Q.push_back(a[j]);
        if((j-i+1)<k)
        {
            j++;
        }else if((j-i+1)==k)
        {
            ans.push_back(Q.front());
            if((Q.front()==a[i]))
            {
                Q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

