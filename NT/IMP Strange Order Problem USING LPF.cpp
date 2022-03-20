
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ? 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 = n = 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1

#include<bits/stdc++.h>
using namespace std;
int main() {
    int size=2*(pow(10,6));
    int *lpf=new int[size+1];
    for(int i=0;i<=size;i++)
    {
        lpf[i]=i;
    }
    for(int i=2;(i*i)<=size;i++)
    {
        if(lpf[i]==i)
        {
            int cur=i,mul=i;
            while((cur*mul)<=size)
            {
                if(lpf[(cur*mul)]==(cur*mul))
                {
                    lpf[(cur*mul)]=i;
                }
                mul++;
            }
        }
    }
    int n;
    cin>>n;
    bool *arr=new bool[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=false;
    }
    for(int i=n;i>=1;i--)
    {
        if(!arr[i])
        {
            int elem=i;
            int cur_prime=lpf[elem];
            set<int,greater<int>> temp;
            while(cur_prime!=1)
            {
                for(int j=i;j>=1;j-=(cur_prime))
                {
					if(arr[j]==false)
                    {
                        temp.insert(j);
                    	arr[j]=true;
                    }
                }
            	while((elem%cur_prime)==0)
                {
                    elem=elem/cur_prime;
                }
                cur_prime=lpf[elem];
            }
            for(auto it=temp.begin();it!=temp.end();it++)
            {
                cout<<(*it)<<' ';
            }
        }
    }
    cout<<1;
}















