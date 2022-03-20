
In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

Alice is very weak in maths section. Help her to find the number of such n digit integers.

Input Format
The first line contains T, the number of test cases. Further T lines contains the value n which is the number of digit in the integer.

Constraints
1<=T<=20
1<=n<=25

Output Format
For each test case print the number of such n digit integer.

Sample Input
3
1
2
3
Sample Output
#1 : 2
#2 : 3
#3 : 5
Explanation
For n=1 : integers = a, b . For n=2 : integers = aa, ab, ba For n=3 : integers = aaa, aab, aba, baa, bab

#include<bits/stdc++.h>
using namespace std;
int func(int n,int start)
{
	if(n==1)
	{
		return 1;
	}
	if(start==0)
	{
		return func(n-1,0)+func(n-1,1);
	}
	return func(n-1,0);
}
int main()
{
	int t;
	cin>>t;
    int i=1;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=func(n,0)+func(n,1);
		cout<<"#"<<i<<" : "<<ans<<endl;		
        i++;
	}
}
