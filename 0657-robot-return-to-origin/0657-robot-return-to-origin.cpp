class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int updown = 0;
        int leftright = 0;
        for(char c: moves){
            if(c == 'U'){
                updown++;
            }else if(c == 'D'){
                updown--;
            }
            else if(c == 'L'){
                leftright++;
            }else{
                leftright--;
            }
        }
        return updown==0 && leftright == 0;
    }
};