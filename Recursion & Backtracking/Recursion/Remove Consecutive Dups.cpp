
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

void func(char *inp,int i,char prev)
{
    if(inp[i]=='\0')
    {
        return ;
    }
    char cur_ch=inp[i];
    if(cur_ch==prev)
    {
        for(int k=i;inp[k]!='\0';k++)
        {
            inp[k]=inp[k+1];
        }
        prev=cur_ch;
        func(inp,i,prev);
    }else{
        prev=cur_ch;
        func(inp,i+1,prev);
    }
}
void removeConsecutiveDuplicates(char *input) {
    func(input,0,'A');
}





