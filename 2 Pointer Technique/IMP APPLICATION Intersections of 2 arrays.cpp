
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n=A.size(),m=B.size();
    int i=0,j=0;
    vector<int> ans;
    while(i<n&&(j<m))
    {
        if(A[i]<B[j])
        {
            i++;
        }else if(A[i]>B[j])
        {
            j++;
        }else{
            ans.push_back(A[i]);
            i++;j++;
        }
    }
    return ans;
}

