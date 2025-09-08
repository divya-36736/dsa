class Solution {
public:
    bool isNozero(int x){
        while(x>0){
            if(x%10 == 0) return false;
            x /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a<n; a++){
           int b = n-a;
            if(isNozero(a) && isNozero(b)){ //in the a and b 
            //not have any zero
                return {a, b};
            }
        }
        return {};
    }
};