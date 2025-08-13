class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();
        unordered_map<char, int>count1, count2;
        if(s1 != t1) return false;
        for(int i = 0; i<s1; i++){
            count1[s[i]]++; //characters store in map
            count2[t[i]]++;
        }

       return count1 == count2;
    }
};