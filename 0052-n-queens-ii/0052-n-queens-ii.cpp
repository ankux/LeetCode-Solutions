class Solution {
public:
    int N, ans=0;

    bool isValid(int row, int col, vector<string>& board) {
        int i = row, j = col;

        // upward
        while(i >= 0) {
            if(board[i][j] == 'Q') return false;
            i--;
        }

        i = row;

        // left-diagonal
        while(i>=0 && j>=0) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = row, j = col;

        // right-diagonal
        while(i>=0 && j<N) {
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string>& board) {
        if(row >= N) {
            ans++;
            return;
        }

        for(int col = 0; col < N; col++) {
            if( isValid(row, col, board)) {
                board[row][col] = 'Q';
                solve(row+1, board);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return ans;
    }
};