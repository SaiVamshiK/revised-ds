void bubbleSort(int a[], int n)
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]>a[j+1])
                {
                    
                    int t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }
    }
    
    Optimized Implementation: 
The above function always runs O(n^2) time even if the array is sorted. 
It can be optimized by stopping the algorithm if inner loop didn’t cause any swap. 
