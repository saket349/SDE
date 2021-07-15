- Problem statemnt link : <a href="https://leetcode.com/problems/set-matrix-zeroes/" target="_blank">Go</a>
#### first approach is using two arrays, one column another row => If any cell of the matrix has a zero we can record its row and column number. All the cells of this recorded row and column can be marked zero in the next iteration.
-  time  complexity: O(n^2), space complexity: O(n)
```py
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        R = len(matrix)
        C = len(matrix[0])
        rows, cols = set(), set()

        # Essentially, we mark the rows and columns that are to be made zero
        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)

        # Iterate over the array once again and using the rows and cols sets, update the elements
        for i in range(R):
            for j in range(C):
                if i in rows or j in cols:
                    matrix[i][j] = 0
```

#### Next approach is : using first row, and column of matrix as our row, and col matrix
- for first row and column check we use two boolean to know if there is any zero or not

```cpp
def setZeroes(matrix):
        R = len(matrix)    # to capture the length of rows
        C = len(matrix[0]) # to capture no of columns 
        flag = 0  
        #memories rows and columns to be set zero
        for i in range(R):
            if(matrix[i][0]==0):
                flag = 1;
            for j in range(1,C):
                if(matrix[i][j] == 0):
                    matrix[i][0] = 0 
                    matrix[0][j] = 0
        #Iteration over the matrix to modify it
        for i in range(1,R):
            for j in range(1,C):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
        if(matrix[0][0] == 0):
            for i in range(C):
                matrix[0][i] = 0
        if flag:
            for i in range(R):
                matrix[i][0] = 0
```
