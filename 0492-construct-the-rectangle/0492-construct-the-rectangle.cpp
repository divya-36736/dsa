class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mini = INT_MAX;
        int l = 0;
        int w = 0;
        for(int i = 1; i*i<=area; i++){
            if(area%i == 0){
                w = i;
                l = area/i;
                if(l>=w && (l-w)<mini){
                    mini = min(mini, (l-w));
                }
            }
           
        }
        return {l, w};
    }
};