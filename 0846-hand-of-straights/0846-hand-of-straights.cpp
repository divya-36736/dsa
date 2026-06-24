class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        map<int, int> mp;

        for (auto &h : hand) {
            mp[h]++;
        }

        for (auto &it : mp) {

            int ele = it.first;

            while (mp[ele] > 0) {

                mp[ele]--; 

                int curr = ele;

                int cnt = groupSize - 1;

                while (cnt--) {

                    if (mp[curr + 1] <= 0)
                        return false;

                    mp[curr + 1]--;

                    curr++;
                }
            }
        }

        return true;
    }
};