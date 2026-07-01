class Solution {
public:
    bool dfs(int i, int j,int ind,  vector<vector<char>>&board, string &word){
        if(ind == word.size()) return true;

        int n = board.size();
        int m = board[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return false;

        if(board[i][j] != word[ind]) return false;

        char temp = board[i][j]; //stored in temp
        board[i][j] = '#'; //mark it
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int dir = 0; dir<4; dir++){
            int nx = i+dx[dir];
            int ny = j+dy[dir];

            if(dfs(nx, ny, ind+1, board, word)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int x = word.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(dfs(i, j,0, board, word)) return true;
            }
        }
        return false;
    }
};