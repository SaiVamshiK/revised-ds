Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1= N,Q =10^6
1= Ai,Bi =10^9
1=Li=Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5

#include<bits/stdc++.h>
using namespace std;
struct node{
  	int a,b,idx;  
};
void bt(int *a,int *b,node *tree,int s,int e,int i)
{
    if(s==e)
    {
 		tree[i].a=a[s];
        tree[i].b=b[s];
        tree[i].idx=s;
        return ;
    }
    int mid=s+((e-s)/2);
    bt(a,b,tree,s,mid,(2*i));
    bt(a,b,tree,mid+1,e,(2*i)+1);
    node left=tree[(2*i)],right=tree[(2*i)+1];
    if(left.a>(right.a))
    {
        tree[i].a=left.a;
        tree[i].b=left.b;
        tree[i].idx=left.idx;
    }else if(left.a<(right.a))
    {
        tree[i].a=right.a;
        tree[i].b=right.b;
        tree[i].idx=right.idx;
    }else{
        if(left.b<=(right.b))
        {
            tree[i].a=left.a;
        	tree[i].b=left.b;
            tree[i].idx=left.idx;
        }else if(left.b>(right.b))
        {
            tree[i].a=right.a;
        	tree[i].b=right.b;
            tree[i].idx=right.idx;
        }
    }
}
node query(node *tree,int s,int e,int i,int l,int r)
{
    if(l>e||(r<s))
    {
        node ret;
        ret.a=INT_MIN;
        ret.b=INT_MAX;
        ret.idx=-1;
        return ret;
    }
    if((l<=s)&&(r>=e))
    {
        return tree[i];
    }
    int mid=s+((e-s)/2);
    node left=query(tree,s,mid,(2*i),l,r);
    node right=query(tree,mid+1,e,(2*i)+1,l,r);
    if(left.idx!=-1&&(right.idx!=-1))
    {
        node ret;
        if(left.a>(right.a))
        {
            ret.a=left.a;
            ret.b=left.b;
            ret.idx=left.idx;
        }else if(left.a<(right.a))
        {
            ret.a=right.a;
            ret.b=right.b;
            ret.idx=right.idx;
        }else{
            if(left.b<=(right.b))
            {
                ret.a=left.a;
                ret.b=left.b;
                ret.idx=left.idx;
            }else if(left.b>(right.b))
            {
                ret.a=right.a;
                ret.b=right.b;
                ret.idx=right.idx;
            }
        }
        return ret;
    }
    if((left.idx!=-1)&&(right.idx==-1))
    {
        return left;
    }
    if((left.idx==-1)&&(right.idx!=-1))
    {
        return right;
    }
    node ret;
    ret.a=INT_MIN;
    ret.b=INT_MAX;
    ret.idx=-1;
    return ret;
}
int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    node *tree=new node[(4*n)];
    bt(a,b,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {
		int l,r;
        cin>>l>>r;
        l--;r--;
        node ans=query(tree,0,n-1,1,l,r);
        cout<<(ans.idx)+1<<endl;
    }
}



