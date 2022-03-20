

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append 
it at the end to B. If no non-repeating character is found then append '#' at the end of B.

Example Input
Input 1:

 A = "abadbc"
Input 2:

 A = "abcabc"


Example Output
Output 1:

 "aabbdd"
Output 2:

 "aaabc#"


Example Explanation
Explanation 1:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "aba"    -   first non repeating character 'b'
    "abad"   -   first non repeating character 'b'
    "abadb"  -   first non repeating character 'd'
    "abadbc" -   first non repeating character 'd'

string Solution::solve(string s) {
    int n=s.size();
    queue<char> q;
    unordered_map<char,int> mp;
    string ans="";
    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        mp[ch]++;
        q.push(ch);
        while((!q.empty())&&(mp[q.front()]>1))
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

