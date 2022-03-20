void selectionSort(int a[], int n)
    {
        for(int i=0;i<n;i++)
        {
            int minIdx=i,minVal=a[i];
            for(int j=i+1;j<n;j++)
            {
                if(minVal>a[j])
                {
                    minIdx=j;
                    minVal=a[j];
                }
            }
            int t=a[minIdx];
            a[minIdx]=a[i];
            a[i]=t;
        }
    }
