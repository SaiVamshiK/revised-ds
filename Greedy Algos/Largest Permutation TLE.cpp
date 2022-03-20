Problem Description

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.

Input 1:

 A = [1, 2, 3, 4]
 B = 1
Input 2:

 A = [3, 2, 1]
 B = 2


Example Output
Output 1:

 [4, 2, 3, 1]
Output 2:

 [3, 2, 1]

vector<int> Solution::solve(vector<int> &a, int B) {
    int n=a.size();
    vector<int> op;
    set<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        st.insert({a[i],i});
    }
    for(int i=0;i<n;i++)
    {
        int cur=a[i];
        auto it=st.find({cur,i});
        st.erase(it);
        if(st.size()==0)
        {
            op.push_back(cur);
            break;
        }
        auto maxItr=st.end();
        maxItr--;
        int maxVal=(*maxItr).first;
        int a1=i,a2=(*maxItr).second;
        if(cur<maxVal)
        {
            op.push_back(maxVal);
            st.erase(maxItr);
            st.insert({cur,a2});
            swap(a[a1],a[a2]);
            B--;
            if(B==0)
            {
                for(int j=i+1;j<n;j++)
                {
                    op.push_back(a[j]);
                }
                break;
            }
        }else{
            op.push_back(cur);
        }
    }
    return op;
}
