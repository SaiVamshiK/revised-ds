void merge(int inp[],int start,int mid,int end)
{
    int temp[end-start+1];
    int k=0;
    int i=start,j=mid+1;
    while(i<=mid&&(j<=end))
    {
        if(inp[i]<inp[j])
        {
            temp[k++]=inp[i++];
        }else{
            temp[k++]=inp[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=inp[i++];
    }
    while(j<=end)
    {
        temp[k++]=inp[j++];
    }
    for(int x=0,y=start;x<k;x++,y++)
    {
        inp[y]=temp[x];
    }
}
void MS(int inp[],int start,int end)
{
    if(start<end)
    {
        int mid=start+((end-start)/2);
        MS(inp,start,mid);
        MS(inp,mid+1,end);
        merge(inp,start,mid,end);
    }
}
void mergeSort(int input[], int size){
	MS(input,0,size-1);
}














