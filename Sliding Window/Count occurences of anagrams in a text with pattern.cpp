//Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

//Example 1:
//
//Input:
//txt = forxxorfxdofr
//pat = for
//Output: 3
//Explanation: for, orf and ofr appears
//in the txt, hence answer is 3.
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int n=txt.size(),m=pat.size();
	    int pat_arr[26]={0};
	    for(int i=0;i<m;i++)
	    {
	        char ch=pat[i];
	        pat_arr[ch-'a']++;
	    }
	    int window_size=m;
	    int i=0,j=0;
	    int cnt=0;
	    int wind_arr[26]={0};
	    while(j<n)
	    {
	        if((j-i+1)<window_size)
	        {
	            int cur_ch=txt[j];
	            wind_arr[cur_ch-'a']++;
	            j++;
	        }
	        else if((j-i+1)==window_size)
	        {
	            int cur_ch=txt[j];
	            wind_arr[cur_ch-'a']++;
	            bool done=true;
	            for(int i=0;i<26;i++)
	            {
	                if(wind_arr[i]!=pat_arr[i])
	                {
	                    done=false;
	                    break;
	                }
	            }
	            if(done)
	            {
	                cnt++;
	            }
	            wind_arr[txt[i]-'a']--;
	            i++;j++;
	        }
	    }
	    return cnt;
	}

};

