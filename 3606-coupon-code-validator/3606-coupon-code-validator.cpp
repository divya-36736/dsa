class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

       
        vector<string> electronics, grocery, pharmacy, restaurant;

        for (int i = 0; i < n; i++) {
            bool valid = true;

            
            if (code[i].empty()) valid = false;

            for (char c : code[i]) {
                if (!isalnum((unsigned char)c) && c != '_') {
                    valid = false;
                    break;
                }
            }

            if (!isActive[i]) valid = false;

            if (!valid) continue;

            if (businessLine[i] == "electronics")
                electronics.push_back(code[i]);
            else if (businessLine[i] == "grocery")
                grocery.push_back(code[i]);
            else if (businessLine[i] == "pharmacy")
                pharmacy.push_back(code[i]);
            else if (businessLine[i] == "restaurant")
                restaurant.push_back(code[i]);
        }

        
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        vector<string> ans;
        ans.insert(ans.end(), electronics.begin(), electronics.end());
        ans.insert(ans.end(), grocery.begin(), grocery.end());
        ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
        ans.insert(ans.end(), restaurant.begin(), restaurant.end());

        return ans;
    }
};
