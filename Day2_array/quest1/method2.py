# function to modify matrix; set desired rows and columns zero
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
 