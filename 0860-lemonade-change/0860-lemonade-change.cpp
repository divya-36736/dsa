class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int f = 0;
        int t = 0;
        int twt = 0;
        int i = 0;
        while(i<n){
            if(bills[i] == 5) f++;
            if(bills[i] == 10){
                t++;
                if(f >= 1) f--;
                else return false;
            }
            if(bills[i] == 20){
                if((f>=1 && t>=1)){
                    twt++;
                    f--;
                    t--;
                }
                else if(f>=3){
                    twt++;
                    f = f-3;
                }else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};