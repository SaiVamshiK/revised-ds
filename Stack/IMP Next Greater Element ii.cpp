
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

/*

Concept :
to find a string is rotated from an other string wha t to do
Eg.
original string : "aeiou"
rotated string : "ouaei"(Clockwise rotation)
multiply rotated string 2 times : "ou'aeiou'aei"
After multiplying the string you find the original string 

Same thing applies here 
here in above eg elements are
1,2,1 for the last one in circular array we have no elements after that so we find next greater element after last one from beginning
So multiplying array 2 times as 1 2 '1' 1 2 1 
Now for every element in original array if the nearest greater element is not found in the right side of array we move to the beginning 
virtually as array is multiplied 2 times

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            a.push_back(a[i]);
        }
        stack<int> st;
        vector<int> ans;
        for(int i=(2*n)-1;i>=0;i--)
        {
            if(st.empty())
            {
                // append -1 as the answer for the element
                if(i<n)
                {
                    ans.push_back(-1);
                }
                st.push(a[i]);
            }else{
                while((!st.empty())&&(st.top()<=a[i]))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    // append -1 as the answer for the element
                    if(i<n)
                    {
                        ans.push_back(-1);
                    }
                    st.push(a[i]);
                }else{
                    // append st.top() as the answer for the element
                    if(i<n)
                    {
                        ans.push_back(st.top());
                    }
                    st.push(a[i]);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
