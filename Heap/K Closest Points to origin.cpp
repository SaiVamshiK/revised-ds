
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., v(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the ""order"" that it is in).

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            pq.push({pow(a[i][0],2)+pow(a[i][1],2),{a[i][0],a[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp;
            pair<int,int> qwe=pq.top().second;
            temp.push_back(qwe.first);
            temp.push_back(qwe.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};
