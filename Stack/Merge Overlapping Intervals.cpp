/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
#include<bits/stdc++.h> 
using namespace std;
bool comparator(Interval a,Interval b)
{
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &a) {
    sort(a.begin(),a.end(),comparator);
    stack<Interval> st;
    for(int i=0;i<(a.size());i++)
    {
        Interval cur=a[i];
        if(st.empty())
        {
            st.push(cur);
        }else{
            Interval topElem=st.top();
            int si=topElem.start,ei=topElem.end;
            int sj=cur.start,ej=cur.end;
            if(ei>=sj)
            {
                st.pop();
                Interval obj;
                obj.start=si;
                obj.end=max(ei,ej);
                st.push(obj);
            }else{
                st.push(cur);
            }
        }
    }
    vector<Interval> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

