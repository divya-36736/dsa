class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int ans = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '6'){
                ans = i;
                break;
            }
        }
        int offset = 4 - s.size();
        if(ans < 0) return num;
        cout << ans;
        if(ans + offset == 0){
            return num + 3000;
        }
        if(ans + offset == 1){
            return num + 300;
        }
        if(ans + offset == 2){
            return num + 30;
        }
        if(ans + offset == 3){
            return num + 3;
        }
        return num;
    }
};