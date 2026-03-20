class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long currmass = mass;
        for(int i = 0; i<n; i++){
            if(currmass < asteroids[i]) return false;
            currmass += asteroids[i];
        }
        return true;
    }
};