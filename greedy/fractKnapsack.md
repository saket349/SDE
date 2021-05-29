##### idea is to sort elements on the basis of their value to weight ration, in decreasing order

```
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(Item a, Item b) {
    double x = double(a.value)/double(a.weight);
    double y = double(b.value)/double(b.weight);
    return x > y;
}

 double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here+
        sort(arr, arr+n, comp);
        double ans = 0.0;
        for(int i=0;i<n;i++) {
            if(W==0) break;
            if(arr[i].weight <= W){
                ans = ans + double(arr[i].value);
                W = W - arr[i].weight;
            }
            else{
                ans = ans + ( double(arr[i].value) * double(W)/double(arr[i].weight) );
                W = 0;
            }
        }
        
        return ans;
    }
```
