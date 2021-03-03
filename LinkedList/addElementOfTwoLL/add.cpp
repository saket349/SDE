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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* temp;
        ListNode* d = new ListNode();
        temp = d;
        while(l1 != NULL && l2 != NULL){
            sum = 0;
            ListNode* dd = new ListNode();
            sum = l1->val + l2->val + carry;
            dd->val = sum%10;
            carry = sum/10;
            dd->next = NULL;
            temp->next = dd;
            temp = dd;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            sum = l1->val + carry;
            ListNode* dd = new ListNode();
            dd->val = sum%10;
            carry = sum/10;
            dd->next = NULL;
            temp->next = dd;
            temp = dd;
            l1 = l1->next;
            
        }
        while(l2!=NULL){
            sum = l2->val + carry;
            ListNode* dd = new ListNode();
            dd->val = sum%10;
            carry = sum/10;
            dd->next = NULL;
            temp->next = dd;
            temp = dd;
            l2 = l2->next;
        }
        while(carry!=0){
            sum=carry;
            ListNode* dd = new ListNode();
            dd->val = sum%10;
            carry = sum/10;
            dd->next = NULL;
            temp->next = dd;
            temp = dd;
        }
        return d->next;
    }
};