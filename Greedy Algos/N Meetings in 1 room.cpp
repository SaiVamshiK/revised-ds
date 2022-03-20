
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is 
finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room 
at a particular time? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4
Explanation:
Four meetings can be held with
given start and end timings.

struct node{
    int st,et;  
};
bool comparator(node a,node b)
{
    return a.et<b.et;
}
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        node *a=new node[n];
        for(int i=0;i<n;i++)
        {
            a[i].st=start[i];
            a[i].et=end[i];
        }
        sort(a,a+n,comparator);
        int cnt=1,last_end=a[0].et;
        for(int i=1;i<n;i++)
        {
            if(a[i].st>last_end)
            {
                cnt++;
                last_end=a[i].et;
            }
        }
        return cnt;
    }
};


