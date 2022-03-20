

You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7

Input:

First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.

Output:

For each test case, output the number of photographs taken by photographer.

Constraints:

 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M

SAMPLE INPUT

2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4

SAMPLE OUTPUT

4
2




#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
int fact(int n)
{
    if(n==0||(n==1))
    {
        return 1;
    }
    return n*fact(n-1);
}
void dfs(int **board,bool **visited,int i,int j,int n,int m,int &s)
{
    visited[i][j]=true;
    s++;
	// i-1,j+2
    if((i-1>=0)&&(j+2<m)&&(board[i-1][j+2]==1)&&(!visited[i-1][j+2]))
    {
        dfs(board,visited,i-1,j+2,n,m,s);
    }
    // i+1,j+2
    if((i+1<n)&&(j+2<m)&&(board[i+1][j+2]==1)&&(!visited[i+1][j+2]))
    {
        dfs(board,visited,i+1,j+2,n,m,s);
    }
    // i-1,j-2
    if((i-1>=0)&&(j-2>=0)&&(board[i-1][j-2]==1)&&(!visited[i-1][j-2]))
    {
        dfs(board,visited,i-1,j-2,n,m,s);
    }
    // i+1,j-2
    if((i+1<n)&&(j-2>=0)&&(board[i+1][j-2]==1)&&(!visited[i+1][j-2]))
    {
        dfs(board,visited,i+1,j-2,n,m,s);
    }
    // i-2,j+1
    if((i-2>=0)&&(j+1<m)&&(board[i-2][j+1]==1)&&(!visited[i-2][j+1]))
    {
        dfs(board,visited,i-2,j+1,n,m,s);
    }
    // i-2,j-1
    if((i-2>=0)&&(j-1>=0)&&(board[i-2][j-1]==1)&&(!visited[i-2][j-1]))
    {
        dfs(board,visited,i-2,j-1,n,m,s);
    }
    // i+2,j+1
    if((i+2<n)&&(j+1<m)&&(board[i+2][j+1]==1)&&(!visited[i+2][j+1]))
    {
        dfs(board,visited,i+2,j+1,n,m,s);
    }
    // i+2,j-1
    if((i+2<n)&&(j-1>=0)&&(board[i+2][j-1]==1)&&(!visited[i+2][j-1]))
    {
        dfs(board,visited,i+2,j-1,n,m,s);
    }
}
int main()
{
	int t;
    cin>>t;
    ll *fact=new ll[1000001];
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        fact[i]=((i%MOD)*(fact[i-1]%MOD))%MOD;
    }
    while(t--)
    {
        int n,m,h;
        cin>>n>>m>>h;
        int **board=new int*[n];
        for(int i=0;i<n;i++)
        {
            board[i]=new int[m];
            for(int j=0;j<m;j++)
            {
                board[i][j]=0;
            }
        }
        int a,b;
        while(h--)
        {
            cin>>a>>b;
            a--;b--;
            board[a][b]=1;
        }
        bool **visited=new bool*[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new bool[m];
            for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
            }
        }
        long long ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int size=0;
                if((board[i][j]==1)&&(!visited[i][j]))
                {
                    dfs(board,visited,i,j,n,m,size);
                    ans=((ans%MOD)*(fact[size]%MOD))%MOD;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}















