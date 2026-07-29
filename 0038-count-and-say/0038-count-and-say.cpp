class Solution {
public:
    string count(int n){
        if(n == 1) return "1";

        string prev = count(n-1);

        string curr = "";
        int cnt = 1;

        for(int i = 1; i<prev.size(); i++){
            if(prev[i] == prev[i-1]){
                cnt++;
            }else{
                curr += to_string(cnt);
                curr += prev[i - 1];
                cnt = 1;
            }
        }
        curr += to_string(cnt);
        curr += prev.back();
        return curr;
    }

    string countAndSay(int n) {
        
        return count(n);
    }
};