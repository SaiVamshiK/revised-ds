
There are some spherical balloons spread in two-dimensional space. 
For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end 
of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with 
xstart and xend bursts by an arrow shot at x if xstart = x = xend. There is no limit to the number 
of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must 
be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) 
and another arrow at x = 11 (bursting the other two balloons).

struct Node{
    int si,ei;
};  
bool comparator(Node a,Node b)
{
    return a.si<b.si;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        Node *a=new Node[n];
        for(int i=0;i<n;i++)
        {
            a[i].si=points[i][0];
            a[i].ei=points[i][1];
        }
        sort(a,a+n,comparator);
        int startTime=a[0].si,endTime=a[0].ei;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            int curStartTime=a[i].si,curEndTime=a[i].ei;
            if(curStartTime<=endTime)
            {
                if(curEndTime<endTime)
                {
                    startTime=curStartTime;
                    endTime=curEndTime;
                }
            }else{
                cnt++;
                startTime=curStartTime;
                endTime=curEndTime;
            }
        }
        return cnt;
    }
};
