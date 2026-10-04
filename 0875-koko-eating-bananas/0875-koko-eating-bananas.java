
class Solution {
    public long cal(int[] piles, long hoursly){
    long tot = 0;
    for(int pile:piles){
        tot += (pile + hoursly - 1)/hoursly;
    }
    return tot;
}
    public int minEatingSpeed(int[] piles, int h) {
        int maxpiles = 0;
        for(int pile:piles){
            maxpiles = Math.max(maxpiles, pile);
        }
        int st = 1;
        int end = maxpiles;
        int ans = maxpiles;
        while(st <= end){
            int mid = st + (end-st)/2;

            long hour = cal(piles, mid);

            if(hour <= h){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return st;
    }
}