
Given a set of N jobs where each job i has a deadline and profit associated to it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.


Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40).

bool comparator(Job a,Job b)
{
    return a.profit>b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job a[], int n) 
    {
        sort(a,a+n,comparator);
        int maxDeadline=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxDeadline=max(maxDeadline,a[i].dead);
        }
        int *temp=new int[maxDeadline+1];
        for(int i=1;i<=maxDeadline;i++)
        {
            temp[i]=-1;
        }
        int ans=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            int cur_deadline=a[i].dead;
            for(int j=cur_deadline;j>=1;j--)
            {
                if(temp[j]==-1)
                {
                    temp[j]=a[i].profit;
                    break;
                }
            }
        }
        for(int i=1;i<=maxDeadline;i++)
        {
            if(temp[i]!=-1)
            {
                cnt++;
                ans+=temp[i];
            }
        }
        vector<int> fin;
        fin.push_back(cnt);
        fin.push_back(ans);
        return fin;
    } 
};


