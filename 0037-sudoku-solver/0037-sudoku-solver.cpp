class Solution {
public:
    bool isValid(int row, int col, char ch, vector<vector<char>>& board) {

        // checking for same row and col
        for(int i=0; i<9; i++) {
            if(board[i][col] == ch || board[row][i] == ch) {
                return false;
            }
        }

        // checking for 3x3 grid
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;
        for(int i=startRow; i<startRow+3; i++) {
            for(int j=startCol; j<startCol+3; j++) {
                if(board[i][j] == ch) {
                    return false;
                }
            }
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