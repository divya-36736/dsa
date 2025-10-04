class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) continue; 
                    if (digits[i] == 0) continue; 
                    if (digits[k] % 2 != 0) continue;         
                    int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                    st.insert(num);
                }
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};
