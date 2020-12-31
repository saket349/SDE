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
        int count1,count2;
        count1 = count2 = 0;
        while(d1!=NULL)
        {
            count1++;
            d1=d1->next;
        }
        while(d2!=NULL){
            count2++;
            d2=d2->next;
        }
        ListNode* A = new ListNode();
        ListNode* B = new ListNode();
        A->next = headA;
        B->next = headB;
        int diff = abs(count1 - count2);
        if(count1 < count2){
            while(diff){
                B = B->next;
                diff--;
            }
        }else{
            while(diff){
                A = A->next;
                diff--;
            }
        }
        
        while(A!=NULL && B!=NULL){
            if(A->next==B->next)
                return A->next;
            A=A->next;
            B=B->next;
        }
        return A;
    }
};