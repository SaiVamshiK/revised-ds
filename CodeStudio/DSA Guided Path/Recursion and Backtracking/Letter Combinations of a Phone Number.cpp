
Problem Statement
Given a string S containing digits from 2 to 9 inclusive. Your task is to find all possible letter combinations that the number could represent.
A mapping from Digits to Letters (just like in Nokia 1100) is shown below. Note that 1 does not map to any letter.

string nums[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void func(string &s,int i,int n,string &op,vector<string> &ans)
{
    if(i==n)
    {
        ans.push_back(op);
        return ;
    }
    int idx=s[i]-'0';
    idx=idx-2;
    for(int x=0;x<(nums[idx].size());x++)
    {
        op.push_back(nums[idx][x]);
        func(s,i+1,n,op,ans);
        op.pop_back();
    }
}
vector<string> combinations(string s){
    int n=s.size();
    vector<string> ans;
    string op="";
    func(s,0,n,op,ans);
    return ans;
}




