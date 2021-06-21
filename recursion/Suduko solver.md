#### Solution is based on backtracking
- we start with one empty index and fill it with some value and recur and keep doing same, if we are able to completely fill the suduko then we are done
- if not then we use other value and fill then recur and see if we are able to or not
- we keep doing this, and if we are run out of all valid possible number then we know that there is some issue with given suduko and we return false

```cpp
// this function is used to check if for given row and column we can have num as our entry or not
bool isSafe(vector<vector<char>> &board, int row, int col, char ch){     
        // three levels of check
      
        // vertical check: same number should not be in any row of that column index
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
        }
        // horizontal check: same number should not be in any column of that row index
        for(int i=0;i<9;i++)
            if(board[row][i]==ch) return false;
        // block check: should not be in that 3*3 matrix
        int r = (row/3)*3;
        int c = (col/3)*3;
        for(int i=r;i<(r+3);i++){
            for(int j=c;j<(c+3);j++)
                if(board[i][j]==ch) return false;
        }
        return true;
    }
    // find empty row, column each time it is called
    bool findRC(vector<vector<char>> &board, int& row, int& col){
        for(row=0;row<9;row++)
            for(col=0;col<9;col++)
                if(board[row][col]=='.') 
                   return true;
        
        return false;
    }
    // main function 
    bool solve(vector<vector<char>>& board){
     int row, col;
        if(!findRC(board, row, col))   // empty cell or not
            return true;    // success
        
        for(int num=1;num<=9;num++){     // we use each number and check 
            char ch = char(num+'0');     // since our matrix takes char so we convert int to char
            if(isSafe(board, row, col, ch)){   // valid to put that number or not
                board[row][col] = ch;               // do
                if(solve(board)) return true;       // recur
                board[row][col] = '.';              // undo
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
```
