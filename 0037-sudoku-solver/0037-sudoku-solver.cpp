class Solution {
public:
   bool isValid(int row, int col, char ch, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == ch) return false;
            
            // Check column
            if (board[i][col] == ch) return false;
            
            // Check 3x3 subgrid
            int subgridRow = 3 * (row / 3) + i / 3; // Calculate row in subgrid
            int subgridCol = 3 * (col / 3) + i % 3;  // Calculate column in subgrid
            if (board[subgridRow][subgridCol] == ch) return false;
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char ch ='1'; ch <= '9'; ch++) {
                        if(isValid(i, j, ch, board)) {
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};