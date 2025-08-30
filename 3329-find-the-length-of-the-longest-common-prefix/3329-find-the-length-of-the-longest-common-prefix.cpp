class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //brute force approach
        // int maxi = 0;
        // int n1 = arr1.size();
        // int n2 = arr2.size();
        // for (int i = 0; i < n1; i++) {
        //     for (int j = 0; j < n2; j++) {
        //         string s1 = to_string(arr1[i]); //string me convert 
        //         //krna apdega perfix check krne ke liye
        //         string s2 = to_string(arr2[j]);
        //         int k = 0;
        //         while (k < s1.size() && k < s2.size() && s1[k] == s2[k]) {
        //             k++;
        //         }
        //         maxi = max(maxi, k);
        //     }
        // }
        // return maxi;
//while se kro ya isse kro same hi answer aaega

        //optimal solution
        unordered_set<string>set;
        for(int num: arr1){
            string s = to_string(num);
            string prefix = "";
            for(char c: s){
                prefix += c;
                set.insert(prefix);
            }
        }
        int maxi = 0;
        //for arr2
        for(int num: arr2){
            string s = to_string(num);
            string prefix = "";
            for(char c: s){
                prefix += c;
                if(set.count(prefix)){
                    maxi = max(maxi, (int)prefix.length());
                }
            }
        }
        return maxi;
    }
};
