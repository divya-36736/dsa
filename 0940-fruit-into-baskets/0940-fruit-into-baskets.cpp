class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // brute force approach
        // int n = fruits.size();
        // int maxlen = 0;
        // for(int i = 0; i<n; i++){
        //     unordered_set<int>s;
            
        //     for(int j = i; j<n; j++){
        //         s.insert(fruits[j]);
        //         if(s.size() <= 2){
        //             maxlen = max(maxlen, j-i+1);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;

        // optimal

        int n = fruits.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int>m;
        int maxlen = 0;
        while(r<n){
            m[fruits[r]]++;
            if(m.size() > 2){
                while(m.size() > 2){
                    m[fruits[l]]--;
                    if(m[fruits[l]] == 0){
                        m.erase(fruits[l]);
                    }
                    l++;
                }
            }
            maxlen = max(maxlen, r-l+1);   
            r++;
        }
        return maxlen;
    }
};