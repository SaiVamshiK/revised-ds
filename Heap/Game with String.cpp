Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. 
The value of a string is defined as the sum of squares of the count of each distinct character.
 

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22

class Solution{
public:
    int minValue(string s, int k){
        priority_queue<int> pq;
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push(it->second);
        }
        while(!pq.empty()&&(k--))
        {
            int elem=pq.top();
            pq.pop();
            elem--;
            if(elem!=0)
            {
                pq.push(elem);
            }
        }
        int ans=0;
        while(!pq.empty())
        {
            ans+=pow(pq.top(),2);
            pq.pop();
        }
        return ans;
    }
};
