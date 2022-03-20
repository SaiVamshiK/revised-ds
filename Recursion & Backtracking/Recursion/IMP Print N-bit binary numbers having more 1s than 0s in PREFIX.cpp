Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's

class Solution{
public:	
    void func(vector<string> &ans,int one,int zero,int n,string op,int len)
    {
        if(one==zero)
        {
            if(len!=n)
            {
                op.push_back('1');
                func(ans,one+1,zero,n,op,len+1);
            }else{
                ans.push_back(op);
                return ;
            }
        }else if(one>zero){
            if(len!=n)
            {
                op.push_back('1');
                func(ans,one+1,zero,n,op,len+1);
                op.pop_back();
                op.push_back('0');
                func(ans,one,zero+1,n,op,len+1);
            }else{
                ans.push_back(op);
                return ;
            }
        }
    }
	vector<string> NBitBinary(int n)
	{
	    int one=0,zero=0;
	    vector<string> ans;
	    string op="";
	    func(ans,one,zero,n,op,0);
	    return ans;
	}
};


