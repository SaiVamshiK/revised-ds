Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. 
Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 
8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ



#include <bits/stdc++.h>
using namespace std;

bool isPresent(char **matrix,int si,int sj,int n,int m,bool **visited,int idx,string str)
{
    visited[si][sj]=true;
    if(str[idx]=='\0')
    {
        return true;
    }
    bool ans=false;
    // si+1,sj
    if((si+1<n)&&(!visited[si+1][sj])&&(matrix[si+1][sj]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si+1,sj,n,m,visited,idx+1,str));
    }
    // si,sj-1
    if((sj-1>=0)&&(!visited[si][sj-1])&&(matrix[si][sj-1]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si,sj-1,n,m,visited,idx+1,str));
    }
    // si-1,sj
    if((si-1>=0)&&(!visited[si-1][sj])&&(matrix[si-1][sj]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si-1,sj,n,m,visited,idx+1,str));
    }
    // si,sj+1
    if((sj+1<m)&&(!visited[si][sj+1])&&(matrix[si][sj+1]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si,sj+1,n,m,visited,idx+1,str));
    }
    
    // si+1,sj+1
    if((si+1<n)&&(sj+1<m)&&(!visited[si+1][sj+1])&&(matrix[si+1][sj+1]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si+1,sj+1,n,m,visited,idx+1,str));
    }
    // si+1,sj-1
    if((si+1<n)&&(sj-1>=0)&&(!visited[si+1][sj-1])&&(matrix[si+1][sj-1]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si+1,sj-1,n,m,visited,idx+1,str));
    }
    // si-1,sj-1
    if((si-1>=0)&&(sj-1>=0)&&(!visited[si-1][sj-1])&&(matrix[si-1][sj-1]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si-1,sj-1,n,m,visited,idx+1,str));
    }
    // si-1,sj+1
    if((si-1>=0)&&(sj+1<m)&&(!visited[si-1][sj+1])&&(matrix[si-1][sj+1]==str[idx]))
    {
        ans=ans||(isPresent(matrix,si-1,sj+1,n,m,visited,idx+1,str));
    }
    return ans;
}
void find(string str,char **matrix,int n,int m,bool &done)
{
    bool **visited=new bool*[n];
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
            if(matrix[i][j]==str[0])
            {
                if(isPresent(matrix,i,j,n,m,visited,1,str))
                {
                    done=true;
                    return ;
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        visited[i][j]=false;
                    }
                }
            }
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    set<string> vec;
	    string str;
	    for(int i=0;i<n;i++)
	    {
	        cin>>str;
	        vec.insert(str);
	    }
	    int m;
	    cin>>n>>m;
	    char **matrix=new char*[n];
	    for(int i=0;i<n;i++)
	    {
	        matrix[i]=new char[m];
	        for(int j=0;j<m;j++)
	        {
	            cin>>matrix[i][j];
	        }
	    }
	    bool printed=false;
	    for(auto it=vec.begin();it!=vec.end();it++)
	    {
	        string cur=(*it);
	        bool done=false;
	        find(cur,matrix,n,m,done);
	        if(done)
	        {
	            printed=true;
	            cout<<cur<<' ';
	        }
	    }
	    if(!printed)
	    {
	        cout<<"-1";
	    }
	    cout<<endl;
	}
	return 0;
}
