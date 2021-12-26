- Given k linkedLists, each sorted in asc order
- Task:  Merge k lists and in sorted order

```
Example1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class Object {
        int val; ListNode* node;
        public :
        Object(int _val, ListNode* _node){
            val = _val;
            node = _node;
        }
        int getval() const{
            return val;
        }
        ListNode* getnode() const{
            return node;
        }
    };
    class comparator{
        public:
        int operator() (const Object& o1, const Object& o2){
            return o1.getval() > o2.getval(); 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Object, vector<Object>, comparator> pq;
        ListNode* head;
        ListNode* curr = new ListNode();
        head = curr;
        int list_count = lists.size();
        for(int i=0;i<list_count;i++){
            if(lists[i]!=NULL)
            pq.push(Object(lists[i]->val, lists[i]));
        }
        while(!pq.empty()){
            Object p = pq.top();
            pq.pop();
            ListNode* node = p.getnode();
            if(node->next!=NULL) pq.push(Object(node->next->val, node->next));
            head->next = node;
            head = node;
            
        }
        head = curr->next;
        return head;
    }
};
```
