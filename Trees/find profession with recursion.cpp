
                E
           /        \
          E          D
        /   \       /  \
       E     D     D    E
      / \   / \   / \   / \
     E   D D   E  D  E  E  D

Given level and position of a person in above ancestor tree, find profession of the person.

Examples:

Input : level = 4, pos = 2
Output : Doctor

Input : level = 3, pos = 4
Output : Engineer


#include <bits/stdc++.h>
using namespace std;
char findProfession(int level,int pos)
{
    if(level==1)
    {
        return 'e';
    }
    char parent=findProfession(level-1,((pos-1)/2)+1);
    if(parent=='e')
    {
        // parent is engineer;
        if(pos%2==0)
        {
            return 'd';
        }else{
            return 'e';
        }
    }else{
        // parent is doctor;
        if(pos%2==0)
        {
            return 'e';
        }else{
            return 'd';
        }
    }
}
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int l,p;
	    cin>>l>>p;
	    if(findProfession(l,p)=='e')
	    {
	        cout<<"Engineer"<<endl;
	    }else{
	        cout<<"Doctor"<<endl;
	    }
	}
	return 0;
}









