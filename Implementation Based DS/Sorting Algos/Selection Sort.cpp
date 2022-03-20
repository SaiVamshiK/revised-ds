void selectionSort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int min_pos=i;
        int min_elem=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min_elem)
            {
                min_elem=a[j];
                min_pos=j;
            }
        }
        swap(&a[i],&a[min_pos]);
    }
}
