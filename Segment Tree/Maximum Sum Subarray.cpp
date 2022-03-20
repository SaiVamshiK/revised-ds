
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| = 15007 , 1 = N = 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x = i = j = y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2

#include<bits/stdc++.h>
using namespace std;
struct node{
  	int left_max,right_max,total_max,total_sum;  
};
void bt(int *a,node *tree,int s,int e,int i)
{
    if(s==e)
    {
        tree[i].left_max=a[s];
        tree[i].right_max=a[s];
        tree[i].total_max=a[s];
        tree[i].total_sum=a[s];
        return ;
    }
    int mid=s+((e-s)/2);
    bt(a,tree,s,mid,(2*i));
    bt(a,tree,mid+1,e,1+(2*i));
    node left=tree[(2*i)],right=tree[(2*i)+1];
    tree[i].left_max=max(left.left_max,max(left.total_sum,left.total_sum+right.left_max));
    tree[i].right_max=max(right.right_max,max(right.total_sum,right.total_sum+left.right_max));
    tree[i].total_max=max(
    	left.total_max,
        max(
        	right.total_max,
            max(
            	left.right_max+right.left_max,
                left.total_sum+right.total_sum
            )
        )
    );
    tree[i].total_sum=left.total_sum+right.total_sum;
}
node query(node *tree,int s,int e,int i,int l,int r)
{
 	if(l>e||(r<s))   
    {
        node ret;
        ret.left_max=INT_MIN;
        ret.right_max=INT_MIN;
        ret.total_max=INT_MIN;
        ret.total_sum=INT_MIN;
        return ret;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i];
    }
    int mid=s+((e-s)/2);
    node left=query(tree,s,mid,(2*i),l,r);
    node right=query(tree,mid+1,e,(2*i)+1,l,r);
    node ret;
    if(left.left_max==INT_MIN&&(right.left_max!=INT_MIN))
    {
        return right;
    }
    if(left.left_max!=INT_MIN&&(right.left_max==INT_MIN))
    {
		return left;
    }
    if(left.left_max==INT_MIN&&(right.left_max==INT_MIN))
    {
		node ret;
        ret.left_max=INT_MIN;
        ret.right_max=INT_MIN;
        ret.total_max=INT_MIN;
        ret.total_sum=INT_MIN;
        return ret;
    }
    ret.left_max=max(left.left_max,max(left.total_sum,left.total_sum+right.left_max));
    ret.right_max=max(right.right_max,max(right.total_sum,right.total_sum+left.right_max));
    ret.total_max=max(
    	left.total_max,
        max(
        	right.total_max,
            max(
            	left.right_max+right.left_max,
                left.total_sum+right.total_sum
            )
        )
    );
    ret.total_sum=left.total_sum+right.total_sum;
    return ret;
}
int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    node *tree=new node[(4*n)];
    bt(a,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        node ans=query(tree,0,n-1,1,l,r);
        cout<<ans.total_max<<endl;
    }
}
