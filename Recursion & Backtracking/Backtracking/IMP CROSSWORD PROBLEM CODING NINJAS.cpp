
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. 
Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA



#include<bits/stdc++.h>
using namespace std;
bool isVertical(char **mat,int row,int col,string cur)
{
    int n=cur.size();
    int idx=0;
    for(int i=row;i<10&&(idx<n);i++)
    {
        if(mat[i][col]=='-'||(mat[i][col]==cur[idx]))
        {
            
        }
        else{
            return false;
        }
        idx++;
    }
    if(idx==n)
    {
        return true;
    }
    return false;
}
bool isHorizontal(char **mat,int row,int col,string cur)
{
    int n=cur.size();
    int idx=0;
    for(int i=col;i<10&&(idx<n);i++)
    {
        if(mat[row][i]=='-'||(mat[row][i]==cur[idx]))
        {
            
        }else{
            return false;
        }
        idx++;
    }
    if(idx==n)
    {
        return true;
    }
    return false;
}
void setVertical(char **mat,int row,int col,string cur,bool *visited)
{
    int n=cur.size();
    int idx=0;
    for(int i=row;i<10&&(idx<n);i++)
    {
        if(mat[i][col]!=cur[idx])
        {
            mat[i][col]=cur[idx];
            visited[idx]=true;
        }
        idx++;
    }
}
void setHorizontal(char **mat,int row,int col,string cur,bool *visited)
{
    int n=cur.size();
    int idx=0;
    for(int i=col;i<10&&(idx<n);i++)
    {
        if(mat[row][i]!=cur[idx])
        {
            mat[row][i]=cur[idx];
            visited[idx]=true;
        }
        idx++;
    }
}
void resetVertical(char **mat,int row,int col,string cur,bool *visited)
{
    int n=cur.size();
    int idx=0;
    for(int i=row;i<10&&(idx<n);i++)
    {
        if(visited[idx])
        {
            mat[i][col]='-';
        }
        idx++;
    }
}
void resetHorizontal(char **mat,int row,int col,string cur,bool *visited)
{
    int n=cur.size();
    int idx=0;
    for(int i=col;i<10&&(idx<n);i++)
    {
        if(visited[idx])
        {
            mat[row][i]='-';
        }
        idx++;
    }
}
void func(char **mat,vector<string> &words,int idx,bool &ans)
{
    if(idx==words.size())
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
        ans=true;
        return ;
    }
    string cur=words[idx];
    int n=cur.size();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((mat[i][j]=='-')||(mat[i][j]==cur[0]))
            {
                if(isHorizontal(mat,i,j,cur))
                {
                    bool *visited=new bool[n];
                    for(int i=0;i<n;i++)
                    {
                        visited[i]=false;
                    }
                    setHorizontal(mat,i,j,cur,visited);
                    func(mat,words,idx+1,ans);
                    if(ans)
                    {
                        return ;
                    }
                    resetHorizontal(mat,i,j,cur,visited);
                }
                if(isVertical(mat,i,j,cur))
                {
                    bool *visited=new bool[n];
                    for(int i=0;i<n;i++)
                    {
                        visited[i]=false;
                    }
                    setVertical(mat,i,j,cur,visited);
                    func(mat,words,idx+1,ans);
                    if(ans)
                    {
                        return ;
                    }
                    resetVertical(mat,i,j,cur,visited);
                }
            }
        }
    }
}
int main() {
    char **mat=new char*[10];
    for(int i=0;i<10;i++)
    {
        mat[i]=new char[10];
        for(int j=0;j<10;j++)
        {
            cin>>mat[i][j];
        }
    }
    string str;
    cin>>str;
    string x;
    vector<string> words;
    for(int i=0;i<(str.size());i++)
    {
        if(str[i]==';')
        {
            words.push_back(x);
            x="";
        }else{
            x.push_back(str[i]);
        }
    }
    words.push_back(x);
    bool ans=false;
    func(mat,words,0,ans);
}
























