- [question link] (https://leetcode.com/problems/rotate-list/)
```
Given the head of a linked list, rotate the list to the right by k places.
```
![image](https://user-images.githubusercontent.com/62437314/157818996-b65b68ce-a3c4-47a6-8048-8d360010d016.png)
```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

```cpp
ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* x = head;
        int l = 1;
        while(x->next!=NULL){
            x = x->next;
            l++;
        }
        x->next = head;
        k = k%l;
        for(int i=0;i<l-k;i++){
            x = x->next;
        }
        head = x->next;
        x->next = nullptr;
        return head;
    }
```
