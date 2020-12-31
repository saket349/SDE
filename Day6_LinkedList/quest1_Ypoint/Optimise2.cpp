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
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode* d1;
        ListNode* d2;
        d1 = headA;
        d2 = headB;
        while(true){
            if(d1==d2)
                return d1;
            d1=d1->next;
            d2=d2->next;
            if(d1==NULL && d2==NULL)
                break;
            if(d1==NULL){
                d1=headB;
            }
            if(d2==NULL){
                d2=headA;
            }
        }
        return d1;
    }
};