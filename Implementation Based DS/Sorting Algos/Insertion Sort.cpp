
class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int a[], int n)
    {
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            int cur=a[i];
            while(j>=0&&(a[j]>cur))
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                j--;
            }
        }
    }
};
