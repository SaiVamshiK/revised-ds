Given a NxM matrix containing Uppercase English Alphabets only. 
Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. 
For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
#include<bits/stdc++.h>
bool func(vector<vector<char>> &a,int si,int sj,int n,int m,char *str,bool **visited)
{
    visited[si][sj]=true;
    char ch=str[0];
    if(ch=='\0')
    {
        return true;
    }
    bool ans=false;
    if((sj+1<m)&&(a[si][sj+1]==ch)&&(!visited[si][sj+1]))
    {
        ans=ans||func(a,si,sj+1,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((si+1<n)&&(sj+1<m)&&(a[si+1][sj+1]==ch)&&(!visited[si+1][sj+1]))
    {
        ans=ans||func(a,si+1,sj+1,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((si+1<n)&&(a[si+1][sj]==ch)&&(!visited[si+1][sj]))
    {
        ans=ans||func(a,si+1,sj,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((si+1<n)&&(sj-1>=0)&&(a[si+1][sj-1]==ch)&&(!visited[si+1][sj-1]))
    {
        ans=ans||func(a,si+1,sj-1,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((sj-1>=0)&&(a[si][sj-1]==ch)&&(!visited[si][sj-1]))
    {
        ans=ans||func(a,si,sj-1,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((si-1>=0)&&(sj-1>=0)&&(a[si-1][sj-1]==ch)&&(!visited[si-1][sj-1]))
    {
        ans=ans||func(a,si-1,sj-1,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((si-1>=0)&&(a[si-1][sj]==ch)&&(!visited[si-1][sj]))
    {
        ans=ans||func(a,si-1,sj,n,m,str+1,visited);
        if(ans) return ans;
    }
    if((si-1>=0)&&(sj+1<m)&&(a[si-1][sj+1]==ch)&&(!visited[si-1][sj+1]))
    {
        ans=ans||func(a,si-1,sj+1,n,m,str+1,visited);
        if(ans) return ans;
    }
    return ans;
}

bool hasPath(vector<vector<char>> &a, int n, int m) {
    bool **visited=new bool*[n];
    char arr[]="CODINGNINJA";
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='C')
            {
                bool temp=func(a,i,j,n,m,arr+1,visited);
                if(temp)
                {
                    return true;
                }  
				// no need to reinitialize the visited matrix with false        
            }
        }
    }
    return false;
}




