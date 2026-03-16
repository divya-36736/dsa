class Solution {
public:
    int nextGreaterElement(int n) {
        //approach is next permutation 
        string s = to_string(n);
        int n1 = s.size();
        int i = n1-2;
        while(i>=0 && s[i] >= s[i+1]){
            i--;
        }
        
        if(i<0) return -1;

        int j = n1-1;
        while(s[j] <= s[i]){
            j--;
        }

        //swap
        swap(s[j], s[i]);

        reverse(s.begin()+i+1, s.end());
        long long ans = stoll(s);
        if(ans > INT_MAX) return -1;

        return ans;
    }
};