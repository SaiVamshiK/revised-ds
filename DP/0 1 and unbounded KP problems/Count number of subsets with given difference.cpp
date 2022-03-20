***************
Count of subset sum:
	0....................S1..............|...............S2...................sum
	S2-S1=diff
	now diff is given
	we have S1+S2=sum
	we need to count the number of subsets with given diff
	so for that we have to find how many pairs of(S1,S2) exists such that their diff is as given
	
	we have S2=sum-S1
	substitute in S2-S1=diff
	=> sum-(2*S1)=diff
	S1=(sum-diff)/2;
	count the number of subsets with sum=S1
	Automatically we get S2 if we get S1
	therefore counting the number of subsets with sum=S1 will give us the answer of the count of subsets with given diff
	
