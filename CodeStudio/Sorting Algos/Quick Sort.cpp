
int findP(int a[],int low,int high)
{
    int i=low,j=high;
    int pivot=a[low];
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            //swap(a[i],a[j]);
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //swap(a[low],a[j]);
    int t=a[low];
    a[low]=a[j];
    a[j]=t;
    return j;
}

void QS(int a[],int low,int high)
{
    if(low<high)
    {
        int j=findP(a,low,high);
        QS(a,low,j-1);
        QS(a,j+1,high);
    }
}
