
Replace every element with the least greater element on its right

Given an array of integers, replace every element with the least greater element on its right side in the array. 
If there are no greater element on the right side, replace it with -1.


A naive method is to run two loops. 
The outer loop will one by one pick array elements from left to right. 
The inner loop will find the smallest element greater than the picked element on its right side. 
Finally, the outer loop will replace the picked element with the element found by inner loop. 
The time complexity of this method will be O(n2).


A tricky solution would be to use Binary Search Trees.
We start scanning the array from right to left and insert each element into the BST. 
For each inserted element, we replace it in the array by its inorder successor in BST. 
If the element inserted is the maximum so far (i.e. its inorder successor doesn’t exist), we replace it by -1.
