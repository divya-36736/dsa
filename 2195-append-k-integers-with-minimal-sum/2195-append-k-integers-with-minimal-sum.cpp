class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());  // remove duplicates
        //sum kth elements and in array any elements is appear of equal and less than k then we delete that element and add the next k+1 element to it
        long long ans = (long(k) * (long(k+1)))/2;
        for(int s: st){
            if(s<=k){
                ans += k+1;
                ans -= s;
                k++;
            }else{
                break;
            }
        }
        return ans;
    }
};
