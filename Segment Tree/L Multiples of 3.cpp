
There are N numbers a[0],a[1]..a[N - 1]. Initally all are 0. You have to perform two types of operations :

1) Increase the numbers between indices A and B by 1. This is represented by the command "0 A B"

2) Answer how many numbers between indices A and B are divisible by 3. This is represented by the command "1 A B".

Input :

The first line contains two integers, N and Q. Each of the next Q lines are either of the form "0 A B" or "1 A B" as mentioned above.

Output :

Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.

Sample Input :
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3

Sample Output :
4
1
0
2

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
struct node{
	int mod_zero,mod_one,mod_two;
};
// update(tree,lazy,0,n-1,1,a,b);
void update(node *tree,int *lazy,int s,int e,int i,int l,int r)
{
	if(lazy[i]!=0)
	{
		int val=(lazy[i]%3);
		int zero=tree[i].mod_zero;
		int one=tree[i].mod_one;
		int two=tree[i].mod_two;
		if(val==1)
		{
			tree[i].mod_zero=two;
			tree[i].mod_one=zero;
			tree[i].mod_two=one;
		}
		if(val==2)
		{
			tree[i].mod_zero=one;
			tree[i].mod_one=two;
			tree[i].mod_two=zero;
		}
		if(s!=e)
		{
			lazy[(2*i)]+=(lazy[i]);
			lazy[(2*i)+1]+=(lazy[i]);
		}
		lazy[i]=0;
	}
	if(l>e||(r<s))
	{
		return ;
	}
	if((l<=s)&&(r>=e))
	{
		int zero=tree[i].mod_zero;
		int one=tree[i].mod_one;
		int two=tree[i].mod_two;
		tree[i].mod_zero=two;
		tree[i].mod_one=zero;
		tree[i].mod_two=one;
		if(s!=e)
		{
			lazy[(2*i)]+=1;
			lazy[(2*i)+1]+=1;
		}
		return ;
	}
	int mid=s+((e-s)/2);
	update(tree,lazy,s,mid,(2*i),l,r);
	update(tree,lazy,mid+1,e,(2*i)+1,l,r);
	node left=tree[(2*i)],right=tree[(2*i)+1];
	tree[i].mod_zero=left.mod_zero+right.mod_zero;
	tree[i].mod_one=left.mod_one+right.mod_one;
	tree[i].mod_two=left.mod_two+right.mod_two;
	return ;
}
node query(node *tree,int *lazy,int s,int e,int i,int l,int r)
{
	if(lazy[i]!=0)
	{
		int val=(lazy[i]%3);
		int zero=tree[i].mod_zero;
		int one=tree[i].mod_one;
		int two=tree[i].mod_two;
		if(val==1)
		{
			tree[i].mod_zero=two;
			tree[i].mod_one=zero;
			tree[i].mod_two=one;
		}
		if(val==2)
		{
			tree[i].mod_zero=one;
			tree[i].mod_one=two;
			tree[i].mod_two=zero;
		}
		if(s!=e)
		{
			lazy[(2*i)]+=(lazy[i]);
			lazy[(2*i)+1]+=(lazy[i]);
		}
		lazy[i]=0;
	}
	if(l>e||(r<s))
	{
		node ret;
		ret.mod_zero=0;
		ret.mod_one=0;
		ret.mod_two=0;
		return ret;
	}
	if(l<=s&&(r>=e))
	{
		return tree[i];
	}
	int mid=s+((e-s)/2);
	node ans1=query(tree,lazy,s,mid,(2*i),l,r);
	node ans2=query(tree,lazy,mid+1,e,(2*i)+1,l,r);
	node ret;
	ret.mod_zero=ans1.mod_zero+ans2.mod_zero;
	ret.mod_one=ans1.mod_one+ans2.mod_one;
	ret.mod_two=ans1.mod_two+ans2.mod_two;
	return ret;
}
void bt(node *tree,int s,int e,int i)
{
	if(s==e)
	{
		tree[i].mod_zero=1;
		tree[i].mod_one=0;
		tree[i].mod_two=0;
		return ;
	}
	int mid=s+((e-s)/2);
	bt(tree,s,mid,(2*i));
	bt(tree,mid+1,e,(2*i)+1);
	node left=tree[(2*i)],right=tree[(2*i)+1];
	tree[i].mod_zero=left.mod_zero+right.mod_zero;
	tree[i].mod_one=left.mod_one+right.mod_one;
	tree[i].mod_two=left.mod_two+right.mod_two;	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q;
	cin>>n>>q;
	node *tree=new node[(4*n)+1];
	int *lazy=new int[(4*n)+1];
	for(int i=0;i<=(4*n);i++)
	{
		lazy[i]=0;
	}
	bt(tree,0,n-1,1);
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==0)
		{
			int a,b;
			cin>>a>>b;
			update(tree,lazy,0,n-1,1,a,b);
		}else{
			int a,b;
			cin>>a>>b;
			node ans=query(tree,lazy,0,n-1,1,a,b);
			cout<<(ans.mod_zero)<<endl;
		}
	}
}
