class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        //vector<int> queenPos(n, -1);
        vector<vector<int>> board(n, vector<int> (n, -1));
        queenHelper(n, 0, board, count);
        return count;
    }
    
    bool isValid(int n, int row, int col, vector<vector<int>> &board) {
        // check col
        for(int i=0; i<n; i++) {
            if(i == col)
                continue;
            else if(board[row][i] == 1)
                return false;
        }
        // check rows
        for(int i=0; i<n; i++) {
            if(i == row)
                continue;
            else if(board[i][col] == 1)
                return false;
        }
        // check diglr
        if(row > col) {
            int diff = row - col;
            int r = diff;
            int c = 0;
            while(r <= n-1 && c <= n - 1 - diff) {
                if(r == row && c == col){
                    r++;
                    c++;
                }
                else if(board[r][c] == 1)
                    return false;
                r++;
                c++;
            }
        } else {
            int diff = col - row;
            int r = 0;
            int c = diff;
            while(r <= n-1-diff && c <= n-1){
                if(r == row && c == col){
                    r++;
                    c++;
                }
                else if(board[r][c] == 1)
                    return false;
                r++;
                c++;
            }
        }
        // check digrl
        int r = row-1;
        int c = col+1;
        // go to top left
        while(r >=0 && c <= n-1){
            if(board[r][c] == 1)
                return false;
            r--;
            c++;
        }
        r = row+1;
        c = col-1;
        // go to top left
        while(r <= n-1 && c >= 0){
            if(board[r][c] == 1)
                return false;
            r++;
            c--;
        }
    
        // go to bottom right
        return true;
    }
    
    void queenHelper(int n, int row, vector<vector<int>> &board, int &count) {
        if(row == n){
            count += 1;
            return;
        }
        for(int i=0; i < n; i++) {
            if(isValid(n, row, i, board)){
                board[row][i] = 1;
                queenHelper(n, row+1, board, count);   
                board[row][i] = -1;
            }
        }
    }
};
