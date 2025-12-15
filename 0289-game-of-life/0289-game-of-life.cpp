class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        int x[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int y[] = {1, 1, 0, -1, -1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;

                // neighbors
                for (int dir = 0; dir < 8; dir++) {
                    int dx = i + x[dir];
                    int dy = j + y[dir];

                    if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                        if (board[dx][dy] == 1 || board[dx][dy] == -1) //-1 means in previous state cell is alive
                            cnt++;
                    }
                }

                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = -1;  // live to dead
                } else {
                    if (cnt == 3)
                        board[i][j] = 2;   //dead to live
                }
            }
        }
        //update
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -1) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};
