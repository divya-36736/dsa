class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        // unordered_map<int,int>candy;
        // for(int i = 0; i<n; i++){
        //     candy[candyType[i]]++;
        // }
        int caneat = n/2;
        unordered_set<int>candy(candyType.begin(), candyType.end());
        //alice can only eat n/2
        int size = candy.size();
        if(size>caneat) return caneat;
        return size;
    }
};