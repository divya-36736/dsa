class Solution {
public:
    bool isAnagram(string s, string t) {
    //     //if total counts of per char is equal in both 
    //     //then true otherwise faLSE
    //     int s1 = s.size();
    //     int t1 = t.size();
    //     unordered_map<char, int>count1, count2;
    //     if(s1 != t1) return false;
    //     for(int i = 0; i<s1; i++){
    //         count1[s[i]]++; //characters store in map
    //         count2[t[i]]++;
    //     }
    //     //only check counts if equal then true
    //    return count1 == count2;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s.size() != t.size())  return false;
    for(int i = 0; i<s.size(); i++){
        if(s[i] != t[i]){
            return false;
        }
    }
    return true;
    }
};