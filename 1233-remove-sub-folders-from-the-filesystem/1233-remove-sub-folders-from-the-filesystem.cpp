class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        string prev = "";

        for (string &f : folder) {
            // If f is NOT a subfolder of prev
            if (prev.empty() || f.find(prev + "/") != 0) {
                ans.push_back(f);
                prev = f;
            }
        }
        return ans;
    }
};
