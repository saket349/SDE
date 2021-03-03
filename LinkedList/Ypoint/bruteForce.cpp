/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* q = new ListNode();
        q->next = headB;
        
        while(q!=NULL){
            
            ListNode* p = new ListNode();
            p->next = headA;
            while(p!=NULL){
            if(p->next==q->next)
                return q->next;
            p=p->next;
            }
            q=q->next;
        }
        return q;
    }
};