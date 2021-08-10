// time complexity: O(nlogn), space compelxity: O(1)
```cpp
void nextPer(int *a,int n)
{
    int first, second;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {first = i;break;}
    }
    //cout<<first<<endl;
    for(int i=n-1;i>first;i--)
    {
        if(a[i]>a[first])
        {second = i;break;}
    }
    swap(a[first],a[second]);
    sort(a+first+1,a+n);
    fo(i,n)
    cout<<a[i]<<" ";
}
```
