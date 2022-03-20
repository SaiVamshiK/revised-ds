
This year when tourist visited India for codsule 2019. He and Rajat started discussing few problems on divide 
and conquer. tourist asked Rajat that if you have 2 strings s1 and s2 can you find if they are equivalent. 
Rajat then asked the condition for being equivalent to which tourist replied

Two strings a and b of equal length are called equivalent in one of the two cases:

They are equal.
If we split string a into two halves of the same size a1 and a2, and string b into two halves of the same size 
b1 and b2, then one of the following is correct:
a1 is equivalent to b1, and a2 is equivalent to b2
a1 is equivalent to b2, and a2 is equivalent to b1
Rajat quickly solved the problem can you?

Input Format
First line is number of test cases t Then follow two strings each of same length

Constraints
1 <= test cases <= 10 1 <= string length <= 50000

Output Format
print "YES" if they are "equivalent" and "NO" if they are not


#include<bits/stdc++.h>
using namespace std;
bool isEqual(string a,string b)
{
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
bool isEqualent(string a,string b)
{
	int n=a.size(),m=b.size();
	if((n==0&&(m==0))||(isEqual(a,b)))
	{
		return true;
	}
	if(n%2!=0)
	{
		return false;
	}
	if(n==0||(m==0))
	{
		return false;
	}
	// a1,a2
	// b1,b2
	// Equalent => (a1,b1) && (a2,b2)
	// Equalent => (a1,b2) && (a2,b1)
	bool op11=isEqualent(a.substr(0,n/2),b.substr(0,m/2)),op12=isEqualent(a.substr(n/2,n/2),b.substr(m/2,m/2));
	bool op21=isEqualent(a.substr(0,n/2),b.substr(m/2,m/2)),op22=isEqualent(a.substr(n/2,n/2),b.substr(0,m/2));
	return (op11&&op12)||(op21&&op22);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int n=a.size(),m=b.size();
		if(n!=m)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(n%2!=0)
		{
			if(isEqual(a,b))
			{
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
			continue;
		}
		if(isEqualent(a,b))
		{
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}


