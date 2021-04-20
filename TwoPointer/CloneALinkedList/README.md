<p> First approach is using hashmap, where we create a hashtable of type<node,node> so we just now traverse through the list create deepcopy<br>
  TC: O(n), SC: O(n)
  </p>
 
 <p> Second approach :- <br>
  TC: O(n), SC: O(1) </p>
  //   step 1: we create copy of every node and assign them as next node of every node
  //   step 2: assign node->random copy to node-> copy
  //  step 3: getting back orginal set and assign node copy next as node->next copy
  
  
 ```
 
 
 ```
  
