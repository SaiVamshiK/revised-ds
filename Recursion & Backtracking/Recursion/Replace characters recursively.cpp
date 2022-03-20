Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)
Output Format :
Updated string

void func(char inp[],char c1,char c2,int i)
{
	if(inp[i]=='\0')
    {
		return ;
    }
    if(inp[i]==c1)
    {
        inp[i]=c2;
        func(inp,c1,c2,i+1);
    }else{
        func(inp,c1,c2,i+1);
    }
}
void replaceCharacter(char input[], char c1, char c2) {
    func(input,c1,c2,0);
}

















