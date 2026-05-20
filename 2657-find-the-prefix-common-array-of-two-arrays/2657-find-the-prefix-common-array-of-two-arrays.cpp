class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();

        vector<int> ans;
        
        unordered_set<int> prevA;
        unordered_set<int> prevB;

        int common = 0;

        for (int i = 0; i < n; i++) {

            int curr1 = A[i];
            int curr2 = B[i];

            
            if (prevB.count(curr1))
                common++;

            
            if (prevA.count(curr2))
                common++;
                
            if (curr1 == curr2)
                common++;

            prevA.insert(curr1);
            prevB.insert(curr2);

            ans.push_back(common);
        }

        return ans;
    }
};