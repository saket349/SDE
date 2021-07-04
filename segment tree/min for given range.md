- [Qusetion link](https://practice.geeksforgeeks.org/problems/range-minimum-query/1#)
- for single query question, linear serach ca be done, but for large query question, time complexity will be high
- so we use segment tree concept and do pre-calculation to store the min for range l to r

##### first we construct the tree
```cpp
// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si){
    if(ss==se){
        st[si] = arr[ss];
        return st[si];
    }
    
    int mid = (ss+se)/2;
    st[si] = min(constructSTUtil(arr, ss, mid, st, 2*si+1),
                 constructSTUtil(arr, mid+1, se, st, 2*si+2));
    return st[si];
    
}

/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)(pow(2,x)) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
  //Your code here
}
```
