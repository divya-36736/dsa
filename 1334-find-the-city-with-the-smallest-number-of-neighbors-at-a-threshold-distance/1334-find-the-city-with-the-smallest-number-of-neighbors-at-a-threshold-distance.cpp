class Solution {
public:
    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for(int i=0;i<n;i++)
            mat[i][i] = 0;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        // Floyd Warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    if(mat[i][k] == 1e9 ||
                       mat[k][j] == 1e9)
                        continue;

                    mat[i][j] =
                        min(mat[i][j],
                            mat[i][k] + mat[k][j]);
                }
            }
        }

        int cityNo = -1;
        int cntcity = INT_MAX;

        for(int city=0; city<n; city++){

            int cnt = 0;

            for(int adj=0; adj<n; adj++){

                if(mat[city][adj] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= cntcity){
                cntcity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};