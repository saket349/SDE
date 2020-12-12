# function to modify matrix; set desired rows and columns zero
def setZeroes( matrix):
    
    R = len(matrix)    # to capture the length of rows
    C = len(matrix[0]) # to capture no of columns 
    
    rows, cols = set(), set()
    
    #memories rows and columns to be set zero
    for i in range(R):
        for j in range(C):
            if(matrix[i][j] == 0):
                rows.add(i) 
                cols.add(j)
    
    #Iteration over the matrix to modify it
    for i in range(R):
        for j in range(C):
            if(i in rows or j in cols):
                matrix[i][j]=0

R = int(input())
C = int(input())
matrix = []
for i in range(R):          # A for loop for row entries 
    a = [] 
    for j in range(C):      # A for loop for column entries 
        a.append(int(input())) 
    matrix.append(a)

setZeroes(matrix)

for i in range(R): 
    for j in range(C): 
        print(matrix[i][j], end = " ") 
    print() 
 