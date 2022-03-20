
Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and 
append it at the end to B. If no non-repeating character is found then append '#' at the end of B.

string Solution::solve(string str) {
    int n=str.size();
    int arr[26]={0};
    queue<char> q;
    string ans="";
    for(int i=0;i<n;i++)
    {
        arr[str[i]-'a']++;
        q.push(str[i]);
        while(!q.empty()&&(arr[q.front()-'a']!=1))
        {
            q.pop();
        }
        if(q.empty())
        {
            ans.push_back('#');
        }else{
            ans.push_back(q.front());
        }
    }
    return ans;
}
