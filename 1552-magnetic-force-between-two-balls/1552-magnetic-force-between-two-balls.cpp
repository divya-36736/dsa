class Solution {
public:
    bool canPlace(vector<int>&position, int m, long long  d){
        int cnt = 1;
        int lastPos = position[0];
        for(int i = 1; i<position.size(); i++){
            long long dis = position[i] - lastPos;
            if(dis >= d){
                cnt++;
                lastPos = position[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        long long maxDis = position[n-1] - position[0]; //maxDis minforce
        //min distance 1 toh hoga hi
        int ans = 0;
        int st = 1;
        int end = maxDis;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(canPlace(position, m, mid)){
                ans = mid;
                st = mid+1;

            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};