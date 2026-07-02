class Solution {
public:
    int cnt = 0;

    bool issafe(int row, int col, vector<string>& board, int n) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(int row, vector<string>& board, int n) {
        if (row == n) {
            cnt++;
            return;
        }

        // place in all col
        for (int col = 0; col < n; col++) {

            if (issafe(row, col, board, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Recurse
                solve(row + 1, board, n);

                // Backtrack
                board[row][col] = '.';
            }
        }

    }

        int totalNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            solve(0, board, n);
            return cnt;
        }
    };