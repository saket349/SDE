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

ListNode* reverse(ListNode* head){
    ListNode *newHead = NULL;
    while(head != NULL){
        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head=next;
    }
    return newHead;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return 1;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse(slow->next);
        
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val != slow->val){
                return 0;
            }
            head = head->next;
            slow = slow->next;
        }
        
        return 1;
    }
};