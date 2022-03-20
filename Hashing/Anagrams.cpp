
Given an array of strings, return all groups of strings that are anagrams. 
Represent a group by a list of integers representing the index in the original list. 
Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', 
 formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4.
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

vector<vector<int> > Solution::anagrams(const vector<string> &a) {
    vector<vector<int> > ans;
    int n=a.size();
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i])
        {
            continue;
        }
        bool upper=false;
        visited[i]=true;
        int map1[26]={0};
        string cur=a[i];
        for(int k=0;k<(cur.size());k++)
        {
            map1[cur[k]-'a']++;
        }
        vector<int> fin;
        fin.push_back(i+1);
        for(int j=i+1;j<n;j++)
        {
            if(visited[j])
            {
                continue;
            }
            string str=a[j];
            bool done=false;
            int map2[26]={0};
            for(int k=0;k<(str.size());k++)
            {
                map2[str[k]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(map1[i]!=map2[i])
                {
                    done=true;
                    break;
                }
            }
            if(done)
            {
                
            }else{
                upper=true;
                visited[j]=true;
                fin.push_back(j+1);
            }
        }
        if(!upper)
        {
            vector<int> temp;
            temp.push_back(i+1);
            ans.push_back(temp);
        }else{
            ans.push_back(fin);
        }
    }
    return ans;
}

