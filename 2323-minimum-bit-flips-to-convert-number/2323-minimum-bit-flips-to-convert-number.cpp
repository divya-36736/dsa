class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal; //it convert the bits which required 
        //to convert
        //now in ans count the bits
        int cnt = 0 ;
        for(int i = 0; i<31; i++){
            if(ans & (1<<i)){ //used for easily check bit is set or not
                cnt++;
            }
        }
        return cnt;
    }
};