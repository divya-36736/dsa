class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int maxi = num;
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                swap(s[i], s[j]);
                maxi= max(maxi, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return maxi;
    }
};