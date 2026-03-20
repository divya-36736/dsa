class Solution {
public:
    int countCollisions(string directions) {
        //another method
        //front L and last R never collides then we can trim it
        //remaining number of R and L are collides and that is answwer
        int n = directions.size();
        int i = 0;
        while(i<n && directions[i] == 'L') i++;
        int j = n-1;
        while(j>=0 && directions[j] == 'R') j--;
        int cnt = 0;
        for(int k = i; k<=j; k++){
            if(directions[k] == 'L' || directions[k] == 'R'){
                cnt++;
            }
        }
        return cnt;
    }
};