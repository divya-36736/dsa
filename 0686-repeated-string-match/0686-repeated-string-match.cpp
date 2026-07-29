class Solution {
public:
    int isSubstr(string a1, string b){
        int n1 = a1.size();
        int n2 = b.size();
        for(int i = 0; i<=(n1-n2); i++){
            int j;
            for(j = 0; j<n2; j++){
                if(a1[i+j] != b[j]){
                    break;
                }
            }
            if(j == n2) return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        string a1 = a;
        int cnt = 1;
        while(a1.size() < b.size()){
            a1 += a;
            cnt++;
        }
        if(isSubstr(a1, b)){
            return cnt;
        }
        a1 += a;
        cnt++;
        if(isSubstr(a1, b)){
            return cnt;
        }
        return -1;
    }
};