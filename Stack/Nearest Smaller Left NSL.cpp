
Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element 
is on left side.If no small element present on the left print -1.

Example 1:

Input: n = 3
a = {1, 6, 2}
Output: -1 1 1
Explaination: There is no number at the 
left of 1. Smaller number than 6 and 2 is 1.


class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int> st;
        vector<int> ans; 
        for(int i=0;i<n;i++)
        {
            if(st.empty())            
            {
                ans.push_back(-1);
                st.push(a[i]);
            }else{
                while((!st.empty())&&(st.top()>=a[i]))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(-1);
                    st.push(a[i]);
                }else{
                    ans.push_back(st.top());
                    st.push(a[i]);
                }
            }
        }
        return ans;
    }
};
