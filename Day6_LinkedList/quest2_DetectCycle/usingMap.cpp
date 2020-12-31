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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> mp;
        ListNode* p=head;
        while(p!=NULL){
            mp[p]++;
            if(mp[p]>1)
                return 1;
            p=p->next;
        }
        return 0;
    }
};