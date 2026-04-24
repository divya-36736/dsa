class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int left = 0;
        int right= 0;
        int ds = 0;
        for(int i =0; i<n; i++){
            if(moves[i] == 'L') left += +1;
            else if(moves[i] == 'R') right += 1;
            else ds += 1;
        }
        if(left > right) {
            //ds ko left banadenge
            left += ds;
            left = left - right;
            return left;
        }
        else{
            right += ds;
            right = right - left;
            return right;
        }
    }
};