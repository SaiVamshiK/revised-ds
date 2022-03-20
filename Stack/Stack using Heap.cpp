							*************************** IMPLEMENTING A STACK USING HEAPS ***************************						

A stack is a LIFO data structure
To implement it using a heap:
	2,3,4,pop,pop,5,6,pop
	Create timestamps which is represented by an integer
	Maintain an integer called cnt initialized to one.
	When we take an element in the stream of push and pops.
	Take the first element 2 it has time stamp of 1 so take a max heap and push the value {1,2} sorting based on time stamps. 
	So element with maximum time stamp ( last inserted element ) can be obtained in log(n) time at a go. 
	After inserting the element into the heap increment the time stamp value.
	
	Max Heap:
		Here keep incrementing the time stamps and push the elements into the heap {time stamp, element} 
		Sorting is done based on time stamps.
