class Solution {
public:
    bool isSubstr(string& a1, string& b) {
        int n1 = a1.size();
        int n2 = b.size();

        // Try each position in a1 where b could start
        for (int i = 0; i <= n1 - n2; i++) { 
            int j;
            for (j = 0; j < n2; j++) { 
                if (a1[i + j] != b[j]) {
                    break; // mismatch milte hi break
                }
            }
            if (j == n2) { // pura b match ho gaya
                return true;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        // ye hamane isliye liya ki hame a ko bada krna hai
        string a1 = a;
        int cnt = 1; // ek baar toh a add hai hi

        // a ko tnt k badhaenge jb tk ye b<=a1 nhi hojata
        while (a1.size() < b.size()) {
            a1 += a;
            cnt++;
        }
        // jaise hi bda ya equak hua toh check krenge ki b substr gau ta nhi
        if (isSubstr(a1, b)) {
            return cnt;
        }//ek aur badha kr dekhnege
        a1 += a;
        cnt++;
        if (isSubstr(a1, b)) {
            return cnt;
        }
        return -1;
    }
};