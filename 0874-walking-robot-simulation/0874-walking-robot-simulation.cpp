class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>>s;
        for(auto &o:obstacles){
            s.insert({o[0], o[1]});
        }

        int x = 0;
        int y = 0;
        int dir = 0;
        int maxdis = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for (auto cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(s.count({nx, ny})){
                        break;
                    }
                    x = nx;
                    y = ny;

                    maxdis = max(maxdis, x*x + y*y);
                }
            }
        }
        return maxdis;
    }
};