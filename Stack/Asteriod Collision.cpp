
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int> st;
        int i=0;
        while(i<n)
        {
            int cur=a[i];
            if(cur>0)
            {
                st.push(cur);
                i++;
            }else{
                if(!st.empty())
                {
                    if(st.top()>0)
                    {
                        int topAbs=abs(st.top());
                        int curAbs=abs(cur);
                        if(curAbs==topAbs)
                        {
                            st.pop();
                            i++;
                        }else if(curAbs<topAbs)
                        {
                            i++;
                        }else{
                            st.pop();
                        }
                    }else{
                        st.push(cur);
                        i++;
                    }
                }else{
                    st.push(cur);
                    i++;
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
