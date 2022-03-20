
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1

#include<bits/stdc++.h>
using namespace std;
int dp[100001];
void bt(int *a,int *tree,int s,int e,int i)
{
    if(s==e)
    {
        tree[i]=a[s];
        return ;
    }
    int mid=s+((e-s)/2);
    bt(a,tree,s,mid,(2*i));
    bt(a,tree,mid+1,e,(2*i)+1);
    int left=tree[(2*i)],right=tree[(2*i)+1];
    tree[i]=((right)+( ( left*dp[e-mid] )%3 ))%3;
}
void update(int *tree,int s,int e,int i,int idx)
{
    if(s==e&&(s==idx))
    {
        tree[i]=1;
        return ;
    }
    int mid=s+((e-s)/2);
    if(idx<=mid)
    {
        update(tree,s,mid,(2*i),idx);
    }else{
        update(tree,mid+1,e,(2*i)+1,idx);
    }
    int left=tree[(2*i)],right=tree[(2*i)+1];
    tree[i]=((right)+( ( left*dp[e-mid] )%3 ))%3;
}
int query(int *tree,int s,int e,int i,int l,int r)
{
	if(l>e||(r<s))
    {
        return 0;
    }
    if((l<=s)&&(r>=e))
    {
        int ret;
        ret=(tree[i]*dp[r-e])%3;
        return ret;
    }
    int mid=s+((e-s)/2);
    int ans1=query(tree,s,mid,(2*i),l,r);
    int ans2=query(tree,mid+1,e,(2*i)+1,l,r);
    return (ans1+ans2)%3;
}
int main() {
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<100001;i++)
    {
        dp[i]=((2*dp[i-1])%3);
    }
    int n;
    cin>>n;
    string s;
    cin>>s;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
    }
    int *tree=new int[(4*n)];
    bt(a,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {
        int ch;
        cin>>ch;
        if(ch==0)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(tree,0,n-1,1,l,r)<<endl;
        }else{
            int idx;
            cin>>idx;
            update(tree,0,n-1,1,idx);
        }
    }
}



















