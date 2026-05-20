class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> ans;
        
        unordered_set<int> prev1;
        unordered_set<int> prev2;

        
        int common = 0;

        for(int i = 0; i<n; i++){
            int curr1 = A[i];
            int curr2 = B[i];
            if(prev2.count(curr1)){
                common++;
            }

            if(prev1.count(curr2)){
                common++;
            }

            if(curr1 == curr2) common++;

            prev1.insert(curr1);
            prev2.insert(curr2);

            ans.push_back(common);
        }
        return ans;
    }
};