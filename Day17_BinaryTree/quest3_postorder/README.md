## iterative 

1. Right child of 1 exists. 
   Push 3 to stack. Push 1 to stack. Move to left child.
        Stack: 3, 1

2. Right child of 2 exists. 
   Push 5 to stack. Push 2 to stack. Move to left child.
        Stack: 3, 1, 5, 2

3. Right child of 4 doesn't exist. '
   Push 4 to stack. Move to left child.
        Stack: 3, 1, 5, 2, 4

4. Current node is NULL. 
   Pop 4 from stack. Right child of 4 doesn't exist. 
   Print 4. Set current node to NULL.
        Stack: 3, 1, 5, 2

5. Current node is NULL. 
    Pop 2 from stack. Since right child of 2 equals stack top element, 
    pop 5 from stack. Now push 2 to stack.     
    Move current node to right child of 2 i.e. 5
        Stack: 3, 1, 2

6. Right child of 5 doesn't exist. Push 5 to stack. Move to left child.
        Stack: 3, 1, 2, 5

7. Current node is NULL. Pop 5 from stack. Right child of 5 doesn't exist. 
   Print 5. Set current node to NULL.
        Stack: 3, 1, 2

8. Current node is NULL. Pop 2 from stack. 
   Right child of 2 is not equal to stack top element. 
   Print 2. Set current node to NULL.
        Stack: 3, 1

9. Current node is NULL. Pop 1 from stack. 
   Since right child of 1 equals stack top element, pop 3 from stack. 
   Now push 1 to stack. Move current node to right child of 1 i.e. 3
        Stack: 1

10. Repeat the same as above steps and Print 6, 7 and 3. 
    Pop 1 and Print 1.
