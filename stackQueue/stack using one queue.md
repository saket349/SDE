- only change in push, instead of using two queue we use one, so we need to reverse the entries everytime push is called

```cpp
void Stack::push(int val)
{
    //  Get previous size of queue
    int s = q.size();
 
    // Push current element
    q.push(val);
 
    // Pop (or Dequeue) all previous
    // elements and put them after current
    // element
    for (int i=0; i<s; i++)
    {
        // this will add front element into
        // rear of queue
        q.push(q.front());
 
        // this will delete front element
        q.pop();
    }
}
```
