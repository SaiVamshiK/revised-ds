Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

#include <bits/stdc++.h>
using namespace std;
string arr[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> func(int num)
{
    int w=num/10;
    if(w==0)
    {
        int p=num%10;
        vector<string> ret;
        if(p==0||(p==1))
        {
            return ret;
        }
        string u=arr[p-2];
        for(int i=0;i<(u.size());i++)
        {
            string b;
            b.push_back(u[i]);
            ret.push_back(b);
        }
        return ret;
    }
    vector<string> temp=func(num/10);
    int cur=num%10;
    string cur_str=arr[cur-2];
    vector<string> ans;
    for(int i=0;i<(cur_str.size());i++)
    {
        char cur_ch=cur_str[i];
     	for(int j=0;j<(temp.size());j++)
        {
			string q=temp[j];
            q.push_back(cur_ch);
            ans.push_back(q);
        }   
    }
    return ans;
}
int keypad(int num, string output[]){
    vector<string> ans=func(num);
    for(int i=0;i<(ans.size());i++)
    {
        output[i]=ans[i];
    }
    return ans.size();
}








