
![Screenshot (71)](https://user-images.githubusercontent.com/62437314/126429554-ffa44092-5b91-419a-b1ae-a097814fbf9d.png)

- we reverse in pair of k
- while reversing for any slot (with k length), we have head of that slot as prev, and tail as head
- so we now now connect tail of curr slot with next interation slot's head
- and return curr head (prev) 
```cpp
    ListNode*  solve(ListNode* head, int k, int n){
        if(head == NULL) return NULL;
        if(n < k) return head;
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;
        while(curr!=NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL)
        head->next = solve(next, k, n-k);
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*  dummy = head;
        int n = 0;
        while(dummy){
            n++;
            dummy = dummy->next;
        }
        head = solve(head, k, n);
        return head;
    }
```
