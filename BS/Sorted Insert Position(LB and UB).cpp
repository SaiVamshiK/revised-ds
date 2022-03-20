 
int Solution::searchInsert(vector<int> &A, int val) {
    auto it=lower_bound(A.begin(),A.end(),val);
    return (it-A.begin());
}
LOWER BOUND:
	1st element's iterator that is >=key
UPPER BOUND:
	1st element's iterator that is >key
	
COUNTING OOCURENCES OF A KEY
	upper_bound(a,a+n,key)-lower_bound(a,a+n,key) (always true)
if the count=0 then not present key
or to check whether element is there or not make a call to binary_search(a,a+n,key);
It returns true if element is present else false

LOWER BOUND:
	
Input: 10 20 30 40 50
Output: lower_bound for element 30 at index 2

Input: 10 20 30 30 30 40 50
Output: lower_bound for element 30 at index 2

Input: 10 20 30 40 50
Output: lower_bound for element 35 at index 3

Vector contains : 10 20 30 30 30 40 50

lower_bound for element 30 at position : 2
lower_bound for element 35 at position : 5
lower_bound for element 55 at position : 7

UPPER BOUND:

Vector contains : 10 20 30 40 50
upper_bound for element 35 is at position : 3
upper_bound for element 45 is at position : 4

Input : 10 20 30 30 40 50
Output : upper_bound for element 30 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 45 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 60 is at index 5
