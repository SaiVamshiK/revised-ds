struct node{
    int x,y;  
};
class Solution{
    public:
    //Complete this function
    int gcd(int a,int b)
    {
        if(a<b)
        {
            return gcd(b,a);
        }
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    node EEA(int a,int b)
    {
        if(b==0)
        {
            node ans;
            ans.x=1;
            ans.y=0;
            return ans;
        }
        node temp=EEA(b,a%b);
        node ans;
        ans.x=temp.y;
        ans.y=((temp.x)-((a/b)*(temp.y)));
        return ans;
    }
    int modInverse(int a, int m)
    {
        if((m==1)||(gcd(a,m)!=1))
        {
            return -1;
        }
        if(a>m)
        {
            node ans=EEA(a,m);
            return (ans.x+m)%m;
        }else{
            node ans=EEA(m,a);
            return (ans.y+m)%m;
        }
    }
};
