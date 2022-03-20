Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]


void Solution::sortColors(vector<int> &a) {
    int n=a.size();
    int low=0,high=n-1;
    int mid=0;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[mid],a[low]);
            low++;
            mid++;
        }else if(a[mid]==1)
        {
            mid++;
        }else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}

