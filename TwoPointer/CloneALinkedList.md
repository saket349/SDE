#### First approach is using hashmap, where we create a hashtable of type<node,node> so we just now traverse through the list create deepcopy<br> TC: O(n), SC: O(n)
 
#### Second approach :- <br> TC: O(n), SC: O(1) 
  - step 1: we create copy of every node and assign them as next node of every node
  - step 2: assign node->random copy to node-> copy
  - step 3: getting back orginal set and assign node copy next as node->next copy
  
  
 ```
 class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr;
        Node* temp;
        curr = head;
        
        while(curr){
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
  
        curr = head;
        while(curr){
            if(curr->next)
                curr->next->random = curr->random? curr->random->next: curr->random;
            
            curr = curr->next? curr->next->next: curr->next;
        }
        
    
        curr = head;
        Node* newHead;
        newHead = head? head->next: head;
        Node* dummy = newHead;
        while(curr){
            curr->next = curr->next->next;
            temp = curr->next;
            if(temp)
                dummy->next = temp->next;
            else dummy->next = temp;
            
            curr = temp;
            if(temp) dummy = temp->next;
            else dummy = temp;
        }
     return  newHead;
    }
};

 ```
  
