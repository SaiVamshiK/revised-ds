class Solution {
public:
    bool isValid(string s)
    {
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                st.push(ch);
            }else if(ch==')')
            {
                if(st.empty())
                {
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
    }
    pair<int,int> getMin(string str)
    {
        int n=str.size();
        stack<int> st;
        int open=0,close=0;
        for(int i=0;i<n;i++)
        {
            char ch=str[i];
            if(ch=='(')
            {
                st.push(ch);
            }else if(ch==')')
            {
                if(st.empty())
                {
                    close++;
                }else{
                    st.pop();
                }
            }
        }
        open+=st.size();
        return {open,close};
    }
    void func(string &inp,int idx,int n,string &output,int op,int cl,int open,int close,set<string> &ans,int &req_size)
    {
        if(open==0&&(close==0))
        {
            if(isValid(output)&&(output.size()==req_size))
            {
                ans.insert(output);
                return ;
            }
        }
        if(idx==n)
        {
            return ;
        }
        char ch=inp[idx];
        if(ch=='(')
        {
            if(op==cl)
            {
                output.push_back(ch);
                func(inp,idx+1,n,output,op+1,cl,open,close,ans,req_size);
                output.pop_back();
                if(open>0)
                {
                    func(inp,idx+1,n,output,op,cl,open-1,close,ans,req_size);
                }
            }else{
                output.push_back(ch);
                func(inp,idx+1,n,output,op+1,cl,open,close,ans,req_size);
                output.pop_back();
                if(open>0)
                {
                    func(inp,idx+1,n,output,op,cl,open-1,close,ans,req_size);
                }
            }
        }else if(ch==')')
        {
            if(op==cl)
            {
                if(close>0)
                {
                    func(inp,idx+1,n,output,op,cl,open,close-1,ans,req_size);
                }
            }else{
                output.push_back(ch);
                func(inp,idx+1,n,output,op,cl+1,open,close,ans,req_size);
                output.pop_back();
                if(close>0)
                {
                    func(inp,idx+1,n,output,op,cl,open,close-1,ans,req_size);
                }
            }
        }else{
            output.push_back(ch);
            func(inp,idx+1,n,output,op,cl,open,close,ans,req_size);
            output.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        pair<int,int> t=getMin(s);
        int open=t.first;
        int close=t.second;
        cout<<"Open:"<<open<<" Close:"<<close<<endl;
        string output="";
        int n=s.size();
        set<string> ans;
        int req_size=n-open-close;
        func(s,0,n,output,0,0,open,close,ans,req_size);
        vector<string> ret;
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            ret.push_back((*it));
        }
        return ret;
    }
};











