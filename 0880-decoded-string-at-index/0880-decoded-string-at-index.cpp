class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        long long size = 0;
        //calculate total length
        for(auto &c: s){
            if(isdigit(c)){
                size *= (c-'0');
            }
            else{
                size++;
            }
        }
        //after calculating total length now we shrink the lenth and cal kth element
        for(int i = n-1; i>=0; i--){
            k %= size;
            if(k == 0 && isalpha(s[i])){
                return string(1, s[i]);
            }
            if(isdigit(s[i])){
                size /= (s[i]-'0');
            }else{
                size--;
            }
        }
        return "";
    }
};